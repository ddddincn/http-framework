#include "server.h"

void weather(HttpRequest* request, HttpResponse* response) {
}

void initRoute() {
    HttpConn::ADD_ROUTE("/api/weather", std::bind(weather, std::placeholders::_1, std::placeholders::_2));
}

int main() {
    initRoute();
    Server server(
        1316, 3, 60000, false,           /* 端口 ET模式 timeoutMs 优雅退出  */
        "ip", 3306, "user", "pwd", "db", /* Mysql配置 */
        4, 6);                           /* 连接池数量 线程池数量*/
    server.Start();
}
