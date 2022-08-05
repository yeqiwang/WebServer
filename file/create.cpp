#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
    // 创建文件
    // int open(const char *pathname, int flags, mode_t mode);
        flag: 必选 O_RDONLY, O_WRONLY, or O_RDWR
            可选  O_CLOEXEC,  O_CREAT,  O_DIRECTORY,  O_EXCL,  O_NOCTTY,  O_NOFOLLOW,  O_TMPFILE， O_TRUNC
            flag 参数是一个int型数据，占四个字节，32位， 每一位代表一个标志，多个flag时需要进行或运算|

        mode: 表示创建出来的文件的操作权限 0755 
            最终权限：mode & ~umask(0022)
            0777 -> 111 111 111
            0755 -> 111 101 101
            umask作用 抹去用户的某些权限
*/

int main() {
    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);

    if (fd == -1) {
        perror("open");
    }

    close(fd);

    return 0;
}