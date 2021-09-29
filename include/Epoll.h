//
// Created by wangzitu on 2021/9/26.
//
/**
 * 一个方法类 method class
 * 封装epoll的方法和状态
 * 全局唯一 epoll_fd 维护在 ServerSocket 中
 * **/


#ifndef WEBSERVER_NEW_EPOLL_H
#define WEBSERVER_NEW_EPOLL_H

#include "Http/HttpData.h"
#include "Socket/ServerSocket.h"
#include <sys/epoll.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class Epoll {
public:
    static int funInit_(int _max_event);

    static int funAddFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _httpdata);

    static int funModFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _http_data);

    static int funDelFD_(int _epoll_fd, int _fd, __uint32_t _events, std::shared_ptr<HttpData> _http_data);

    static std::vector<std::shared_ptr<HttpData>>
    funPolling_(const ServerSocket &_server_socket, int _max_event, int _timeout);

    //accept()一个连接
    static void funHandleConnection_(const ServerSocket& _server_socket);

public:
    static std::unordered_map<int, std::shared_ptr<HttpData>> map_fd_to_httpdata_;

    static const int MAX_EVENTS_;

    static epoll_event* events_;

    //事件模式： EPOLLIN | EPOLLET | EPOLLONESHOT
    const static __uint32_t DEFAULT_EVENTS;
};


#endif //WEBSERVER_NEW_EPOLL_H
