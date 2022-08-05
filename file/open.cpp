#include <sys/types.h>
#include <sys/stat.h>
// 定义宏 只读、只写...

#include <fcntl.h>
// 函数声明

#include <stdio.h>
#include <unistd.h>

int main() {
    // 打开文件
    // flag 操作权限  O_RDONLY, O_WRONLY, or O_RDWR
    // 返回文件描述符 -1表示失败
    // errno 属于系统函数库，表示一个全局变量，记录最近的错误号
    // perrno 打印错误描述，参数为用户的错误描述
    // int open(const char *pathname, int flags);

    

    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
    }



    close(fd);

    return 0;
}