#include "config.h"
#include "webserver.h"

using namespace std;


int main(int argc, char *argv[]) {
    //数据库信息，登录名，密码，库名
    string user = "root";
    string password = "root";
    string databasename = "qgydb";

    // 命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
            config.OPT_LINGER, config.TRIGMode, config.sql_num, config.thread_num,
            config.close_log, config.actor_model);

    return 0;
}
