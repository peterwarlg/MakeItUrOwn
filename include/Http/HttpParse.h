//
// Created by wangzitu on 2021/9/25.
//

#ifndef WEBSERVER_NEW_HTTPPARSE_H
#define WEBSERVER_NEW_HTTPPARSE_H

#include "HttpEnum.h"
#include "HttpRequest.h"

class HttpRequestParse {
public:
    //解析一行数据
    static ENUM_LINE_STATE _fooParseLine(char* __buffer, int &__checked_index, int& __read_index);

    //解析请求行
    static ENUM_HTTP_CODE _fooParseRequestLine(char* __line, ENUM_PARSE_STATE &__parse_state, HttpRequest& __request);

    //解析请求头
    static ENUM_HTTP_CODE _fooParseSingleHeaders(char* __line, ENUM_PARSE_STATE &__parse_state, HttpRequest& __request);

    //解析请求主体
    static ENUM_HTTP_CODE
    _fooParseBody(char *__body, HttpRequest &__request);

    static ENUM_HTTP_CODE
    _fooParseContent(char* _buffer, int& _check_index, int& _read_index, ENUM_PARSE_STATE& _parse_state,
                     int& _start_line, HttpRequest& __request);

};

#endif //WEBSERVER_NEW_HTTPPARSE_H
