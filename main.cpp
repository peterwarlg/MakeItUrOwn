#include <iostream>
#include "include/Server.h"
#include "include/Util.h"

using namespace std;



int main() {
    const char* cur_path = getcwd(NULL, 0);
    std::cout << "文件路径 : " << cur_path << std::endl;

    int port = 7244;
    char temp_path[256];
    handle_for_sigpipe();

    HttpServer http_server(port);
    http_server.funRun_(1);
    return 0;
}
