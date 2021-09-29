//
// Created by wangzitu on 2021/9/24.
//

#include "../../include/Socket/ServerSocket.h"
#include <cstring>
#include <cstdio>
#include <fcntl.h>

#define MAX_NUM_OF_LISTEN_FD 1024

void funSetReusePort(int _fd) {
    int option = 1;
    //setsockopt()用来设置参数s 所指定的socket 状态.
    //设置为reuse
    setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, (const void*)&option, sizeof(option));
}

ServerSocket::ServerSocket(int _port, const char *_ip) : server_listen_port_(_port), server_ip_(_ip){
    //ServerSocket的初始化
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(server_listen_port_);

    if (_ip != nullptr) {
        ::inet_pton(AF_INET, _ip, &addr_.sin_addr);
    } else {
        addr_.sin_addr.s_addr = htonl(INADDR_ANY);
    }

    server_listen_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_listen_fd_ == -1) {
        printf("Create Listen Socket fd Error%s%d\n", __FILE__, __LINE__);
        exit(0);
    }
    funSetReusePort(server_listen_fd_);

    //设置为非阻塞IO
    int old_FL = fcntl(server_listen_fd_, F_GETFL);
    int new_FL = old_FL | O_NONBLOCK;
    fcntl(server_listen_fd_, F_SETFL, new_FL);
}

void ServerSocket::funBind_() {
    if (bind(server_listen_fd_, (sockaddr *)&addr_, sizeof(addr_)) == -1) {
        std::cout << "Bind Server Listen Socket Error in " << __FILE__ << " at " << __LINE__ << std::endl;
        exit(0);
    }
}

void ServerSocket::funListen_() {
    if (listen(server_listen_fd_, MAX_NUM_OF_LISTEN_FD) == -1) {
        std::cout << "Listen Server Socket Error in " << __FILE__ << " at " << __LINE__ << std::endl;
        exit(0);
    }
}


int ServerSocket::funAccept_(ClientSocket &_client_socket) const {
    int client_fd = accept(server_listen_fd_, NULL, NULL);
    if (client_fd < 0) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            return client_fd;
        }
        std::cout << "funAccept_ error in file <" << __FILE__ << "> "<< "at " << __LINE__ << std::endl;
        std::cout << "clientfd:" << client_fd << std::endl;
        perror("accpet error");
    }
    _client_socket.client_fd_ = client_fd;
    return client_fd;
}

void ServerSocket::funCloseServer_() {
    if (server_listen_fd_ > 0) {
        ::close(server_listen_fd_);
        server_listen_fd_ = -1;
    }
}

ServerSocket::~ServerSocket() {
    funCloseServer_();
}

