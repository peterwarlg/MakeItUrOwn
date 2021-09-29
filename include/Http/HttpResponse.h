//
// Created by wangzitu on 2021/9/24.
//

#ifndef WEBSERVER_NEW_HTTPRESPONSE_H
#define WEBSERVER_NEW_HTTPRESPONSE_H

#include "HttpRequest.h"
#include <memory>

extern std::unordered_map<std::string, MimeType> g_mime_map;

class HttpResponse {
public:
    explicit HttpResponse(bool __keep_alive = true) :
            response_status_code_(Unknow), response_keep_alive_(__keep_alive), response_mime_("text/html"), response_body_(nullptr),
            response_http_version_(HTTP_11) {};

    void funSetStatusCode_(ENUM_HTTP_STATUS_CODE __code) {
        response_status_code_ = __code;
    }

    void funSetBody_(const char *str) {
        response_body_ = str;
    }

    void funSetContentLength_(int len) {
        response_contend_length_ = len;
    }

    void funSetVersion_(ENUM_HTTP_VERSION __version) {
        response_http_version_ = __version;
    }

    void funSetStatusMsg_(const std::string &__str) {
        reponse_status_code_str_ = __str;
    }

    void funSetFilePath_(const std::string &__path) {
        response_file_path_ = __path;
    }

    void funSetMime_(const MimeType &__mime) {
        response_mime_ = __mime;
    }

    void funSetKeepAlive_(bool __is_alive) {
        response_keep_alive_ = __is_alive;
    }

    void funAddHeader_(const std::string &__key, const std::string &__value) {
        key_value_of_header_in_response_[__key] = __value;
    }

    bool funAskKeepAlive_() const {
        return response_keep_alive_;
    }

    const ENUM_HTTP_VERSION funGetVersion_() const {
        return response_http_version_;
    }

    const std::string funGetFilePath_() const {
        return response_file_path_;
    }

    ENUM_HTTP_STATUS_CODE funGetStatusCode_() const {
        return response_status_code_;
    }

    const std::string &funGetStatusMsg_() const {
        return reponse_status_code_str_;
    }

    void funAppendResponseLineToBuffer_(char *buffer) const;

    ~HttpResponse() {
        if (response_body_ != nullptr) {
            delete[] response_body_;
        }
    }

private:
    //状态码
    ENUM_HTTP_STATUS_CODE response_status_code_;

    //http版本
    ENUM_HTTP_VERSION response_http_version_;

    //TO ADD NOTION
    std::string reponse_status_code_str_;

    bool response_keep_alive_;

    MimeType response_mime_;

    const char *response_body_;

    int response_contend_length_;

    std::string response_file_path_;

    //也是头部字段信息
    std::unordered_map<std::string, std::string> key_value_of_header_in_response_;
};

#endif //WEBSERVER_NEW_HTTPRESPONSE_H
