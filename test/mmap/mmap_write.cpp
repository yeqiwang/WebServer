#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <iostream>

int main(int argc, char* argv[]) {
    char buffer[6] = "nihao";

    int fd = open(argv[1], O_RDWR | O_CREAT, 0664);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    ftruncate(fd, sizeof(buffer));

    char* mm = (char*)mmap(NULL, sizeof(buffer)+1, PROT_READ | PROT_READ, MAP_SHARED, fd, 0);
    if (mm == MAP_FAILED) {
        perror(mm);
        return -1;
    }

    close(fd);
    
    strcpy(mm, buffer);
    return 0;
}