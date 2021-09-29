//
// Created by wangzitu on 2021/9/24.
//

#include "../../include/Http/HttpRequest.h"

std::ostream &operator<<(std::ostream &os, const HttpRequest &__request) {
    os << "Http Method is  : " << __request.method_of_request_ << std::endl;
    os << "Http URL is     : " << __request.uri_of_request_ << std::endl;
    os << "Http Version is : " << __request.version_of_request_ << std::endl;
    os << "The Headers are :" << std::endl;
    for (auto& it : __request.map_header_key_to_str_) {
        os << (int)it.first << " : " << it.second << std::endl;
    }
    return os;
}