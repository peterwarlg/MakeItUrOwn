//
// Created by wangzitu on 2021/9/24.
//
/**
 ServerSocket主要实现socket函数的相关封装
 1.成员函数
    1.1 bind()
    1.2 listen()
    1.3 accept()
    1.4 关闭服务器scoket描述符
2. 成员变量
    2.1 服务器监听端口
    2.2 服务器监听的socket文件描述符
    2.3 epoll的文件描述符
    2.4 服务器IP地址 -> const char *
    2.5 服务器socket_addr
**/

#ifndef WEBSERVER_NEW_SERVERSOCKET_H
#define WEBSERVER_NEW_SERVERSOCKET_H

#include "ClientSocket.h"

#define DEFAULT_SERVER_LISTEN_PORT 8080

//设置端口重用
void funSetReusePort(int _fd);

//Server Class
class ServerSocket {
public:
    ServerSocket(int __port = DEFAULT_SERVER_LISTEN_PORT, const char *__ip = nullptr);

    ~ServerSocket();

    void funBind_();

    void funListen_();

    void funCloseServer_();

    int funAccept_(ClientSocket &_client_socket) const;

public:
    sockaddr_in addr_;
    int server_listen_fd_;
    int epoll_fd_;
    int server_listen_port_;
    const char *server_ip_;
};

#endif //WEBSERVER_NEW_SERVERSOCKET_H
