//
// Created by wangzitu on 2021/9/26.
//

#include "../include/Server.h"
#include "../include/GlobalVar.h"
#include "../include/Epoll.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <string>
#include <functional>
#include <sys/epoll.h>
#include <vector>
#include <cstring>


void HttpServer::funRun_(int thread_num, int _max_queue_size) {
    int epoll_fd = Epoll::funInit_(1024);
    std::shared_ptr<HttpData> http_data(new HttpData());

    http_data->epoll_fd_ = epoll_fd;
    server_socket_.epoll_fd_ = epoll_fd;

    uint32_t event = (EPOLLIN | EPOLLET);

    Epoll::funAddFD_(epoll_fd, server_socket_.server_listen_fd_, event, http_data);

    while (true) {
        std::vector<shared_ptr < HttpData>>
        event_list = Epoll::funPolling_(server_socket_, 1024, -1);
        for (auto &req : event_list) {
            funDoRequest_(req);
            //TODO
        }
    }
}

void HttpServer::funDoRequest_(std::shared_ptr<HttpData> _http_data) {
    char buffer[BUFFERSIZE];
    bzero(buffer, BUFFERSIZE);

    int check_index = 0, read_index = 0, start_line = 0;
    ssize_t recv_data_len;
    ENUM_PARSE_STATE parse_state = PARSE_REQUESTLINE;

    while (true) {
        recv_data_len = recv(_http_data->target_client_socket_->client_fd_, buffer + read_index,
                             BUFFERSIZE - read_index, 0);
        if (recv_data_len == -1) {
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                return;
            }
            std::cout << "Reading Failed" << endl;
            return;
        }

        if (recv_data_len == 0) {
            break;
        }

        read_index += recv_data_len;
        ENUM_HTTP_CODE retcode = HttpRequestParse::_fooParseContent(
                buffer, check_index, read_index, parse_state, start_line, *_http_data->single_request_
        );

        if (retcode == NO_REQUEST) {
            continue;
        }

        if (retcode == GET_REQUEST) {
            _http_data->single_response_->funSetKeepAlive_(false);

            //1. ??????????????????
            funSetHeaderToResponse_(_http_data);

            //2. ??????MIME??????_http_response_????????????url?????????????????????url???????????????????????????basepath????????????????????????
            funGetMimeAndSetPathToResponse_(_http_data, basePath);

            //3. ???????????????????????????response
            ENUM_FILE_STATE file_state = funWriteStaticFileToResponse_(_http_data, basePath.c_str());

            //4. ????????????
            funSend_(_http_data, file_state);

        } else {
            std::cout << "BAD REQUEST" << endl;
        }
    }
}


void HttpServer::funSetHeaderToResponse_(std::shared_ptr<HttpData> _http_data) {
    if (_http_data->single_request_->version_of_request_ == HTTP_11) {
        _http_data->single_response_->funSetVersion_(HTTP_11);
    } else {
        _http_data->single_response_->funSetVersion_(HTTP_10);
    }
    _http_data->single_response_->funAddHeader_("Server", "MakeItUrOwn");
}


//??????mime??????url??????path,???path????????????????????????????????????path???response
void HttpServer::funGetMimeAndSetPathToResponse_(std::shared_ptr<HttpData> _http_data, std::string _base_path) {
    std::string filepath = _http_data->single_request_->uri_of_request_;
    std::string mime;
    int pos;

    if ((pos = filepath.rfind('?')) != std::string::npos) {
        filepath.erase(filepath.rfind('?'));
    }

    //??????mime?????? . ???????????????
    if (filepath.rfind('.') != std::string::npos) {
        mime = filepath.substr(filepath.rfind('.'));
    }

    decltype(g_mime_map)::iterator it;
    if ((it = g_mime_map.find(mime)) != g_mime_map.end()) {
        _http_data->single_response_->funSetMime_(it->second);
    } else {
        _http_data->single_response_->funSetMime_(g_mime_map.find("default")->second);
    }
    //?????????filepath??? "/index1/index2...."?????????url???????????????
    _http_data->single_response_->funSetFilePath_(_base_path + filepath);
}

HttpServer::ENUM_FILE_STATE
HttpServer::funWriteStaticFileToResponse_(std::shared_ptr<HttpData> _http_data, const char *_base_path) {
    struct stat file_stat;
    //????????????????????????????????????  ./filepath... ??????
    char file[strlen(_http_data->single_response_->funGetFilePath_().c_str()) + 1];
    strcpy(file, _http_data->single_response_->funGetFilePath_().c_str());

    if (_http_data->single_response_->funGetFilePath_() == "../" || stat(file, &file_stat) < 0) {
        _http_data->single_response_->funSetMime_(MimeType("text/html"));
        if (_http_data->single_response_->funGetFilePath_() == "../") {
            _http_data->single_response_->funSetStatusCode_(k200ok);
            _http_data->single_response_->funSetStatusMsg_("OK");
            return RETURN_FILE_DEFAULT;
        } else {
            _http_data->single_response_->funSetStatusCode_(k404notfound);
            _http_data->single_response_->funSetStatusMsg_("Not Found");
            return FILE_NOT_FOUND;
        }

    }

    //????????????????????????????????????
    if (!S_ISREG(file_stat.st_mode)) {
        _http_data->single_response_->funSetMime_(MimeType("text/html"));
        _http_data->single_response_->funSetStatusCode_((k403forbiden));
        _http_data->single_response_->funSetStatusCode_(k200ok);
        _http_data->single_response_->funSetStatusMsg_("ForBidden");
        std::cout << "Not Normal File" << endl;
        return FILE_FORBIDDEN;
    }

    _http_data->single_response_->funSetStatusCode_(k200ok);
    _http_data->single_response_->funSetStatusMsg_("OK");
    return FILE_OK;
}

void HttpServer::funSend_(std::shared_ptr<HttpData> _http_data, ENUM_FILE_STATE _file_state) {

    //???????????????????????????
    char header[BUFFERSIZE];
    bzero(header, '\0');
    const char *internal_error = "Internal Error";

    struct stat file_stat;

    //??????????????????header
    _http_data->single_response_->funAppendResponseLineToBuffer_(header);

    //??????header?????????
    int ret = strlen(header);

    if (_file_state == FILE_NOT_FOUND) {
        std::cout << "FILE_NOT_FOUND" << std::endl;
        std::cout << "???????????????" << std::endl;
        _http_data->single_response_->funSetFilePath_(NOT_FOUND_PAGE_PATH);
    } else if (_file_state == FILE_FORBIDDEN) {
        std::cout << "????????????" << std::endl;
        _http_data->single_response_->funSetFilePath_(FORBIDDEN_PAGR_PATH);
    } else if (_file_state == RETURN_FILE_DEFAULT) {
        std::cout << "???????????????" << std::endl;
        _http_data->single_response_->funSetFilePath_(DEFAULT_PAGE_PATH);
    }

    if (stat(_http_data->single_response_->funGetFilePath_().c_str(), &file_stat) < 0) {
        std::cerr << "errno : " << errno << endl;
        std::cout << "?????????????????? ****" << "??????????????????: " << _http_data->single_response_->funGetFilePath_().c_str()
                  << std::endl;
        ret += sprintf(header + ret, "Content-length: %d\r\n\r\n", (int) strlen(internal_error));
        ret += sprintf(header + ret, "%s", internal_error);
        ::send(_http_data->target_client_socket_->client_fd_, header, strlen(header), 0);
        return;
    }

    int file_fd = ::open(_http_data->single_response_->funGetFilePath_().c_str(), O_RDONLY);
    std::cout << "*****FILE PATH***** :  " << _http_data->single_response_->funGetFilePath_().c_str() << std::endl;
    //????????????
    if (file_fd < 0) {
        std::cout << "??????????????????" << std::endl;
        ret += sprintf(header + ret, "Content-length: %d\r\n\r\n", (int) strlen(internal_error));
        ret += sprintf(header + ret, "%s", internal_error);
        ::send(_http_data->target_client_socket_->client_fd_, header, strlen(header), 0);
        ::close(file_fd);
        return;
    }

    ret + sprintf(header + ret, "Content-length: %d\r\n\r\n", (int) file_stat.st_size);
    //????????????
    ::send(_http_data->target_client_socket_->client_fd_, header, strlen(header), 0);

    //????????????
    void *map_buf = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file_fd, 0);
    ::send(_http_data->target_client_socket_->client_fd_, map_buf, file_stat.st_size, 0);

    munmap(map_buf, file_stat.st_size);
    close(file_fd);
    return;
}