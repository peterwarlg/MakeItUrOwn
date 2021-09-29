//
// Created by wangzitu on 2021/9/26.
//

#ifndef WEBSERVER_NEW_SERVER_H
#define WEBSERVER_NEW_SERVER_H

#include "Socket/ServerSocket.h"
#include "Http/HttpParse.h"
#include "Http/HttpData.h"
#include "Http/HttpResponse.h"
#include <memory>

#define BUFFERSIZE 2048

class HttpServer {
public:
    enum ENUM_FILE_STATE {
        FILE_OK,                //文件存在
        FILE_NOT_FOUND,         //文件不存在
        FILE_FORBIDDEN,         //禁止访问
        RETURN_FILE_DEFAULT     //返回默认页
    };

public:
    explicit HttpServer(int _port = 8080, const char *_ip = nullptr) : server_socket_(_port, _ip) {
        server_socket_.funBind_();
        server_socket_.funListen_();
    }

    void funRun_(int, int _max_queue_size = 1000);

    void funDoRequest_(std::shared_ptr<HttpData> _http_data);

private:
    ServerSocket server_socket_;

    void funSetHeaderToResponse_(std::shared_ptr<HttpData> _http_data);

    ENUM_FILE_STATE funWriteStaticFileToResponse_(std::shared_ptr<HttpData> _http_data, const char *_base_path);

    void funSend_(std::shared_ptr<HttpData> _http_data, ENUM_FILE_STATE _file_state);

    void funGetMimeAndSetPathToResponse_(std::shared_ptr<HttpData> _http_data, std::string _base_path);

    void funHandleIndex_();
};


#endif //WEBSERVER_NEW_SERVER_H
