#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#define BUF_SIZE 30

int main(int argc, char *argv[]) {
    fd_set reads, temps;
    int result, str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;  // 超时信息
    
    FD_ZERO(&reads);  // 初始化为0
    FD_SET(0, &reads);  // 文件描述符0置为1，即要监视

    while(1) {
        temps = reads;
        timeout.tv_sec = 5;  // 指定超时时间 5s
        timeout.tv_usec = 0;
        result = select(1, &temps, 0, 0, &timeout); // 调用select函数，监视1个接收类文件描述符
        if (result == -1) {
            puts("select() error!");
            break;
        }
        else if (result == 0) {  // 超时会返回0
            puts("Time-out!");
        }
        else {  // 返回正整数，表示发生了变化
            if (FD_ISSET(0, &temps)) {  // 验证select调用结果, 是否文件描述符0发生了变化
                str_len= read(0, buf, BUF_SIZE); 
                buf[str_len] = 0;
                printf("message from console: %s", buf);
            }
        }
    }
    return 0;
}
