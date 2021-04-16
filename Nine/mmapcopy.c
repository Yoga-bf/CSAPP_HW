#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


int main(int argc, char *argv[])
{
    char *bufq;
    int fd1, fd2;
    fd1 = open(argv[1], "r");
    fd2 = open(argv[1], "r");
    long length  = lseek(fd1, 0, SEEK_END);

    bufq = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd2, 0);
    printf("%s", bufq);
}