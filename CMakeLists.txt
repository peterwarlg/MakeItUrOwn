cmake_minimum_required(VERSION 3.10)
project(webserver_new)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        webserver_new
        main.cpp
        src/Socket/ServerSocket.cpp
        include/Socket/ServerSocket.h
        src/Http/HttpRequest.cpp
        include/Http/HttpRequest.h
        src/Http/HttpResponse.cpp
        include/Http/HttpResponse.h
        include/Http/HttpEnum.h
        src/Http/HttpData.cpp
        include/Http/HttpData.h
        src/Http/HttpParse.cpp
        include/Http/HttpParse.h
        src/Util.cpp
        include/Util.h

        src/Epoll.cpp
        include/Epoll.h
        src/Server.cpp
        include/Server.h
        src/Socket/ClientSocket.cpp
        include/Socket/ClientSocket.h
        include/GlobalVar.h)