//
// Created by wangzitu on 2021/9/27.
//

#include "../../include/Socket/ClientSocket.h"

void ClientSocket::fooCloseClientFD() {
    if (client_fd_ > 0) {
        ::close(client_fd_);
        printf("Close Client fd : %d\n", client_fd_);
        client_fd_ = -1;
    }
}

ClientSocket::~ClientSocket() {
    fooCloseClientFD();
}