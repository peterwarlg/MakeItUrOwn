//
// Created by wangzitu on 2021/9/26.
//

#include "../include/Epoll.h"
#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include <cstdio>

//epoll中 文件描述符 到 httpdata的映射
std::unordered_map<int, std::shared_ptr<HttpData>> Epoll::map_fd_to_httpdata_;
const int Epoll::MAX_EVENTS_ = 1000;
epoll_event *Epoll::events_;

//可读 | ET | ONESHOT
const __uint32_t Epoll::DEFAULT_EVENTS = (EPOLLIN | EPOLLET | EPOLLONESHOT);

int Epoll::funInit_(int _max_event) {
    int epoll_fd = ::epoll_create(_max_event);
    if (epoll_fd == -1) {
        printf("Epoll Create Error\n");
        exit(-1);
    }
    Epoll::events_ = new epoll_event[_max_event];
    return epoll_fd;
}

int Epoll::funAddFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _httpdata) {
    epoll_event event;
    event.events = (EPOLLIN | EPOLLET);
    event.data.fd = _fd;
    //添加事件到Epoll::map中
    Epoll::map_fd_to_httpdata_[_fd] = _httpdata;

    int ret = ::epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _fd, &event);
    if (ret < 0) {
        printf("Epoll ADD ERROR\n");
        Epoll:
        map_fd_to_httpdata_[_fd].reset();
        return -1;
    }
    return 0;
}

int Epoll::funModFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _http_data) {
    epoll_event event;
    event.events = _events;
    event.data.fd = _fd;
    Epoll::map_fd_to_httpdata_[_fd] = _http_data;
    int ret = ::epoll_ctl(_epoll_fd, EPOLL_CTL_MOD, _fd, &event);
    if (ret < 0) {
        printf("EPOLL MODIFY ERROR \n");
        map_fd_to_httpdata_[_fd].reset();
        return -1;
    }
    return 0;
}

int Epoll::funDelFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _http_data) {
    epoll_event event;
    event.events = _events;
    event.data.fd = _fd;
    int ret = ::epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, _fd, &event);
    if (ret < 0) {
        printf("EPOLL DEL ERROR\n");
        return -1;
    }
    auto it = Epoll::map_fd_to_httpdata_.find(_fd);
    if (it != Epoll::map_fd_to_httpdata_.end()) {
        Epoll::map_fd_to_httpdata_.erase(it);
    }
    return 0;
}

void Epoll::funHandleConnection_(const ServerSocket &_server_socket) {
    std::shared_ptr<ClientSocket> tmp_client(new ClientSocket);

    while (_server_socket.funAccept_(*tmp_client) > 0) {
        int ret = setnonblocking(tmp_client->client_fd_);
        if (ret < 0) {
            printf("SET NonBlocking ERROR\n");
            tmp_client->fooCloseClientFD();
            continue;
        }

        //接受新客户端， 构造HttpData
        std::shared_ptr<HttpData> shr_http_data(::new HttpData());
        shr_http_data->single_request_ = std::shared_ptr<HttpRequest>(new HttpRequest());
        shr_http_data->single_response_ = std::shared_ptr<HttpResponse>(new HttpResponse());
        std::shared_ptr<ClientSocket> shr_client_socket(new ClientSocket());
        shr_client_socket.swap(tmp_client);
        shr_http_data->target_client_socket_ = shr_client_socket;
        shr_http_data->epoll_fd_ = _server_socket.epoll_fd_;

        Epoll::funAddFD_(_server_socket.epoll_fd_, shr_client_socket->client_fd_, DEFAULT_EVENTS, shr_http_data);
    }
}

std::vector<std::shared_ptr<HttpData>> Epoll::funPolling_(const ServerSocket &_server_socket, int _max_event,
                                                          int _timeout) {
    int event_num = epoll_wait(_server_socket.epoll_fd_, Epoll::events_, _max_event, _timeout);
    if (event_num < 0) {
        std::cout << "Epoll_num = " << event_num << std::endl;
        std::cout << "epoll_wait ERROR" << std::endl;
        std::cout << errno << std::endl;
        exit(-1);
    }
    std::vector<std::shared_ptr<HttpData>> http_data_list;
    //遍历events集合
    for (int i = 0; i < event_num; i++) {
        int fd = events_[i].data.fd;
        if (fd == _server_socket.server_listen_fd_) {
            Epoll::funHandleConnection_(_server_socket);
        } else {
            if ((events_[i].events & EPOLLERR) ||
                (events_[i].events & EPOLLRDHUP) ||
                (events_[i].events & EPOLLHUP)) {
                auto it = map_fd_to_httpdata_.find(fd);
                if (it != map_fd_to_httpdata_.end()) {
                    it->second.reset();
                    map_fd_to_httpdata_.erase(it);
                }
                continue;
            }

            auto it = map_fd_to_httpdata_.find(fd);
            if (it != map_fd_to_httpdata_.end()) {
                uint32_t cur_event = events_[i].events;
                if ((cur_event & EPOLLIN) || (cur_event & EPOLLPRI)) {
                    http_data_list.push_back(it->second);
                    it->second.reset();
                    map_fd_to_httpdata_.erase(it);
                }
            } else {
                std::cout << "长连接第二次未找到" << std::endl;
                ::close(fd);
                continue;
            }
        }
    }
    return http_data_list;
}