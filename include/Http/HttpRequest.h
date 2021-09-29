//
// Created by wangzitu on 2021/9/24.
//

#ifndef WEBSERVER_NEW_HTTPREQUEST_H
#define WEBSERVER_NEW_HTTPREQUEST_H

#include "HttpEnum.h"
#include <iostream>

class HttpRequest;

std::ostream &operator<<(std::ostream &, const HttpRequest &);

struct HttpRequest {
    friend std::ostream &operator<<(std::ostream &, const HttpRequest &);

    //头部字段的hash表对应的哈希方法
    struct EnumClassHash {
        template<typename T>
        std::size_t operator()(T t) const {
            return static_cast<std::size_t>(t);
        }
    };

    static std::unordered_map<std::string, ENUM_HTTP_HEADER_KEY> map_str_to_header_key_;

    HttpRequest(std::string url = std::string(""),
                ENUM_HTTP_METHOD method = METHOD_NOT_SUPPORT,
                ENUM_HTTP_VERSION version = VERSION_NOT_SUPPORT) :
            method_of_request_(method),
            version_of_request_(version),
            uri_of_request_(url),
            m_contend_(nullptr),
            map_header_key_to_str_(std::unordered_map<ENUM_HTTP_HEADER_KEY, std::string, EnumClassHash>()) {};

    //请求行的三个数据
    ENUM_HTTP_METHOD method_of_request_;
    ENUM_HTTP_VERSION version_of_request_;
    std::string uri_of_request_;

    //请求体？
    char *m_contend_;

    std::unordered_map<ENUM_HTTP_HEADER_KEY, std::string, EnumClassHash> map_header_key_to_str_;
};

#endif //WEBSERVER_NEW_HTTPREQUEST_H
