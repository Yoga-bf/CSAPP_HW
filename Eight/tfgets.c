#include "../csapp.h"
#include <stdio.h>

sigjmp_buf buf;

void handler(int sig) {
    siglongjmp(buf, 1);
}
//程序运行到tfgets后，会设置一个 sigsetmp，然后通过 alarm 设置一个5秒的时钟
//然后程序运行到 return fgets，如果5秒后，fgets 没有返回，这个进程就会收到
//一个 SIGALRM 信号，然后就会执行 handler，进而回到判断语句，返回 NULL
char* tfgets(char* s, int size, FILE* stream) {
    char* result;
    if (!sigsetjmp(buf, 1)) {
        alarm(5);
        if (signal(SIGALRM, handler) == SIG_ERR)
            unix_error("set alarm handler error");
        return fgets(s, size, stream);
    } else {
        return NULL;
    }
}

static int LEN = 100;
int main()
{
    char buff[LEN];
    char *input = tfgets(buff, LEN, stdin);
    if (input == NULL) {
        printf("nothing input\n");
    } else {
        printf("%s", input);
    }
    return 0;
}