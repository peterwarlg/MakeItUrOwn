//
// Created by wangzitu on 2021/9/24.
//

#include "../../include/Http/HttpResponse.h"

typedef size_t BUF_INDEX;

std::unordered_map<std::string, MimeType> g_mime_map = {
        {".html",   "text/html"},
        {".xml",    "text/xml"},
        {".xhtml",  "application/xhtml+xml"},
        {".txt",    "text/plain"},
        {".rtf",    "application/rtf"},
        {".pdf",    "application/pdf"},
        {".word",   "application/msword"},
        {".png",    "image/png"},
        {".gif",    "image/gif"},
        {".jpg",    "image/jpeg"},
        {".jpeg",   "image/jpeg"},
        {".au",     "audio/basic"},
        {".mpeg",   "video/mpeg"},
        {".mpg",    "video/mpeg"},
        {".avi",    "video/x-msvideo"},
        {".gz",     "application/x-gzip"},
        {".tar",    "application/x-tar"},
        {".css",    "text/css"},
        {"",        "text/plain"},
        {"default", "text/plain"}
};

void HttpResponse::funAppendResponseLineToBuffer_(char *buffer) const {
    //buf_index 用于写入
    BUF_INDEX buf_index = 0;

    //判断版本,将状态码{200/403/404} 和 状态信息{OK/BAD}写入buffer
    if (response_http_version_ == HTTP_11) {
        buf_index += sprintf(buffer, "HTTP/1.1 %d %s\r\n", response_status_code_, reponse_status_code_str_.c_str());
    } else {
        buf_index += sprintf(buffer, "HTTP/1.0 %d %s\r\n", response_status_code_, reponse_status_code_str_.c_str());
    }

    //头部字段
    for (auto& it : key_value_of_header_in_response_) {
        buf_index += sprintf(buffer + buf_index, "%s: %s\r\n", it.first.c_str(), it.second.c_str());
    }
    //头部字段Content
    buf_index += sprintf(buffer + buf_index, "Content-type: %s\r\n", response_mime_._type.c_str());

    //头部字段keep-alive
    if (response_keep_alive_) {
        sprintf(buffer + buf_index, "Connection: keep-alive\r\n");
    } else {
        sprintf(buffer + buf_index, "Connection: close\r\n");
    }
}