/*
    #include <unistd.h>

    ssize_t read(int fd, void *buf, size_t count);
        fd 文件描述符
        buf 数据存放位置，数组，传输参数
        count 指定数组大小
    
    返回值
        成功-》返回实际读到的字节数
        失败-》返回-1，设置errno

    ssize_t write(int fd, const void *buf, size_t count);
        fd 文件描述符
        buf 要写的数据
        count 要写入数据的具体大小

    返回值 
        成功-》返回实际写入的字节数
        失败-》返回-1，设置errno

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // open
    int srcfd = open("test.txt", O_RDONLY);

    if (srcfd == -1) {
        perror("open");
        return -1;
    }

    // create new file
    int targetfd = open("test1.txt", O_WRONLY | O_CREAT, 0664);

    if (targetfd == -1) {
        perror("open");
        return -1;
    }
    
    // read write
    char buffer[1024] = {0};
    int len = 0;
    while ((len = read(srcfd, buffer, sizeof(buffer))) > 0) {
        write(targetfd, buffer, len);
    }

    //close
    close(srcfd);
    close(targetfd);

    return 0;
}