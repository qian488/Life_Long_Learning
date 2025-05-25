#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1,fd2;
    fd1 = open("f1.txt",O_RDONLY,0);
    dup(fd1);
    dup2(fd1,6);
    fd2 = open("f2.txt",O_RDONLY,0);
    printf("fd1=%d,fd2=%d\n",fd1,fd2);
    return 0;
}