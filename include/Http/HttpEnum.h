//
// Created by wangzitu on 2021/9/24.
//

#ifndef WEBSERVER_NEW_HTTPENUM_H
#define WEBSERVER_NEW_HTTPENUM_H
#include <string>
#include <unordered_map>

#define CR '\r'
#define LF '\n'
#define LINE_END '\0'
#define PASS

enum ENUM_HTTP_VERSION {
    HTTP_10 = 0,
    HTTP_11,
    VERSION_NOT_SUPPORT
};
enum ENUM_HTTP_METHOD {
    GET = 0,
    POST, PUT, DELETE, METHOD_NOT_SUPPORT
};

enum ENUM_HTTP_HEADER_KEY {
    Host = 0,
    User_Agent,
    Connection,
    Accept_Encoding,
    Accept_Language,
    Accept,
    Cache_Control,
    Upgrade_Insecure_Requests
};

enum ENUM_HTTP_STATUS_CODE {
    Unknow,
    k200ok = 200,
    k403forbiden = 403,
    k404notfound = 404
};

//成员变量只有一个string类
struct MimeType {
    MimeType(const std::string &str) : _type(str) {};

    MimeType(const char *str) : _type(str) {};

    std::string _type;
};



enum ENUM_LINE_STATE {
    LINE_OK = 0, LINE_BAD, LINE_MORE
};
enum ENUM_PARSE_STATE {
    PARSE_REQUESTLINE = 0, PARSE_HEADER, PARSE_BODY
};
enum ENUM_HTTP_CODE {
    NO_REQUEST, GET_REQUEST, BAD_REQUEST, FORBIDDEN_REQUEST, INTERNAL_ERROR,
    CLOSED_CONNECTION
};

#endif //WEBSERVER_NEW_HTTPENUM_H
