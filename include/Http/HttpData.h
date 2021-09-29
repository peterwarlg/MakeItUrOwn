//
// Created by wangzitu on 2021/9/25.
//

#ifndef WEBSERVER_NEW_HTTPDATA_H
#define WEBSERVER_NEW_HTTPDATA_H
#include "../Socket/ServerSocket.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include <memory>

class HttpData : public std::enable_shared_from_this<HttpData> {
public:
    HttpData() : epoll_fd_(-1){
    }

public:
    std::shared_ptr<HttpRequest> single_request_;
    std::shared_ptr<HttpResponse> single_response_;
    std::shared_ptr<ClientSocket> target_client_socket_;
    int epoll_fd_;
};

#endif //WEBSERVER_NEW_HTTPDATA_H
