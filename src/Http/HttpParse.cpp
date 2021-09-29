//
// Created by wangzitu on 2021/9/25.
//

#include "../../include/Http/HttpParse.h"
#include "../../include/Util.h"
#include <string>
#include <algorithm>
#include <cstring>

//HttpRequest中定义的static map
std::unordered_map<std::string, ENUM_HTTP_HEADER_KEY> HttpRequest::map_str_to_header_key_ = { //NOLINT
        {"HOST",                      Host},
        {"USER-AGENT",                User_Agent},
        {"CONNECTION",                Connection},
        {"ACCEPT-ENCODING",           Accept_Encoding},
        {"ACCEPT-LANGUAGE",           Accept_Language},
        {"ACCEPT",                    Accept},
        {"CACHE-CONTROL",             Cache_Control},
        {"UPGRADE-INSECURE-REQUESTS", Upgrade_Insecure_Requests}
};

//解析一行内容， bufer[__checked_index, __read_index)
// check_index是需要分析的第一个字符， read_index已经读取数据末尾下一个字符
ENUM_LINE_STATE HttpRequestParse::_fooParseLine(char *_buffer, int &_checked_index, int &_read_index) {
    char temp;
    for (; _checked_index < _read_index; _checked_index++) {
        temp = _buffer[_checked_index];
        //读到\r,接下来判断是否是最后一行. __read_index是当前读到的数据的长度.
        //LINE_MORE标识socket缓冲区中还有数据要读，也就是一行可能并不完整
        if (temp == CR) {
            if (_checked_index + 1 == _read_index) {
                return LINE_MORE;
            }
            if (_buffer[_checked_index + 1] == LF) {
                //截断。将\r\n置为\0
                _buffer[_checked_index++] = LINE_END;
                _buffer[_checked_index++] = LINE_END;
                return LINE_OK;
            }
            return LINE_BAD;
        }
    }
    return LINE_MORE;
}

//完成request中uri，version，method的处理
ENUM_HTTP_CODE
HttpRequestParse::_fooParseRequestLine(char *_line, ENUM_PARSE_STATE &_parse_state, HttpRequest &_request) {
    //char *url指向url前的那个空格

    char *url = strpbrk(_line, " \t");
    //分割method和url
    *url = '\0';
    url++;
    char *method = _line;

    if (strcasecmp(method, "GET") == 0) {
        _request.method_of_request_ = GET;
    } else if (strcasecmp(method, "POST") == 0) {
        _request.method_of_request_ = POST;
    } else if (strcasecmp(method, "PUT") == 0) {
        _request.method_of_request_ = PUT;
    } else {
        return BAD_REQUEST;
    }

    //返回str1中第一个不在str2中出现的字符的位置
    //保证在method和url中没有空格，url指向报文中url的首地址
    url += strspn(url, " \t");

    //获取version
    char *version = strpbrk(url, " \t");
    if (!version) return BAD_REQUEST;
    *version++ = '\0';
    version += strspn(version, " \t");
    //HTTP/1.1版本号之后还可能存在空格
    if (strncasecmp("HTTP/1.1", version, 8) == 0) {
        _request.version_of_request_ = HTTP_11;
    } else if (strncasecmp("HTTP/1.0", version, 8) == 0) {
        _request.version_of_request_ = HTTP_10;
    } else {
        return BAD_REQUEST;
    }

    //url指向到网页申请的文件
    if (strncasecmp(url, "http://", 7) == 0) {
        url += 7;
        url = strchr(url, '/');
    } else if (strncasecmp(url, "/", 1) == 0) {
        PASS;
    } else {
        return BAD_REQUEST;
    }

    if (!url || *url != '/') {
        return BAD_REQUEST;
    }
    _request.uri_of_request_ = std::string(url);
    _parse_state = PARSE_HEADER;
    return NO_REQUEST;
}


ENUM_HTTP_CODE
HttpRequestParse::_fooParseSingleHeaders(char *_line, ENUM_PARSE_STATE &_parse_state, HttpRequest &_request) {
    if (*_line == '\0') {
        if (_request.method_of_request_ == GET) {
            return GET_REQUEST;
        }
        _parse_state = PARSE_BODY;
        return NO_REQUEST;
    }

    //TODO
    //char key[20]曾被缓冲区溢出;value[100]也被chrome user-agent缓冲区溢出
    //如果之后要加cookies，还需更大缓冲区
    char key[100], value[300];

    //TODO需要修改，有些value里也包含：
    // 取到":"结束，赋值给key和value
    sscanf(_line, "%[^:]:%[^:]", key, value);
    decltype(HttpRequest::map_str_to_header_key_)::iterator it;
    std::string key_s(key);
    //转为大写字母
    std::transform(key_s.begin(), key_s.end(), key_s.begin(), ::toupper);
    std::string value_s(value);

    //查找当前的key是不是可用的，在本项目中有么有定义
    //it的类型是<std::string, ENUM_HTTP_HEADER_KEY>
    //__request.m_head_to_string的类型如名字所示
    if ((it = HttpRequest::map_str_to_header_key_.find(trim(key_s))) != (HttpRequest::map_str_to_header_key_.end())) {
        _request.map_header_key_to_str_.insert(std::make_pair(it->second, trim(value_s)));
    } else {
//        printf("The KEY ： <%s>  in Current Line Is Not Supportted\n", key_s.c_str());
    }
    return NO_REQUEST;
}

//解析body
ENUM_HTTP_CODE
HttpRequestParse::_fooParseBody(char *_body, HttpRequest &_request) {
    _request.m_contend_ = _body;
    return GET_REQUEST;
}

//http请求入口
ENUM_HTTP_CODE
HttpRequestParse::_fooParseContent(char *_buffer, int &_check_index, int &_read_index,
                                   ENUM_PARSE_STATE &_parse_state, int &_start_line, HttpRequest &_request) {
    ENUM_LINE_STATE line_state = LINE_OK;
    ENUM_HTTP_CODE ret_code = NO_REQUEST;

    while ((line_state = _fooParseLine(_buffer, _check_index, _read_index)) == LINE_OK) {
        //本次要处理的数据在buffer中的位置是[_strat_line, _check_index]
        //Attention: buffer是所谓 <用户数据缓冲区> 的长度，处理时应当维护两个变量当作区间
        char *temp = _buffer + _start_line;
        _start_line = _check_index;

        switch (_parse_state) {
            case PARSE_REQUESTLINE: {
                ret_code = _fooParseRequestLine(temp, _parse_state, _request);
                if (ret_code == BAD_REQUEST) {
                    return BAD_REQUEST;
                }
                break;
            }

            case PARSE_HEADER: {
                ret_code = _fooParseSingleHeaders(temp, _parse_state, _request);
                if (ret_code == BAD_REQUEST) {
                    return BAD_REQUEST;
                } else if (ret_code == GET_REQUEST) {
                    return GET_REQUEST;
                }
                break;
            }

            case PARSE_BODY : {
                ret_code = _fooParseBody(temp, _request);
                if (ret_code == GET_REQUEST) {
                    return GET_REQUEST;
                }
                return BAD_REQUEST;
            }

            default:
                return INTERNAL_ERROR;
        }
    }

    if (line_state == LINE_MORE) {
        return NO_REQUEST;
    } else {
        return BAD_REQUEST;
    }
}

