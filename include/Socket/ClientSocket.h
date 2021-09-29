//
// Created by wangzitu on 2021/9/27.
//

#ifndef WEBSERVER_NEW_CLIENTSOCKET_H
#define WEBSERVER_NEW_CLIENTSOCKET_H

#include "../Util.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <memory>

class ClientSocket {
public:
    ClientSocket() {
        client_fd_ = -1;
    }
    ~ClientSocket();

    void fooCloseClientFD();

public:
    int client_fd_;
    socklen_t len_;
    sockaddr_in addr_;
};

#endif //WEBSERVER_NEW_CLIENTSOCKET_H
