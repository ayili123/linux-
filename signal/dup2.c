#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>




int main(void)
{
    int fd;
    int new_fd;

    fd = open("./test.file",O_RDWR|O_CREAT |O_TRUNC,0644);
    printf("fd = %d\n", fd);

    dup2(fd, 1);
    printf("hello world!!\n");

    return 0;
}
