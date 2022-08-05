#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    char sex;
};

int main(int argc, char* argv[]) {
    Student* mm;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    
    mm = (Student*)mmap(NULL, sizeof(Student), PROT_READ | PROT_READ, MAP_SHARED, fd, 0);
    if (mm == MAP_FAILED) {
        perror((char *)mm);
        return -1;
    }
    close(fd);

    printf("id=%d\tname=%s\t%c\n", mm->id, mm->name, mm->sex);
    sleep(2);

    munmap(mm, sizeof(Student));
    return 0;
}