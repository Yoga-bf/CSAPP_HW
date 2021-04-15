#include "../csapp.h"
#include <stdio.h>

sigjmp_buf buf;

void handler(int sig) {
    siglongjmp(buf, 1);
}

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
    char buf[LEN];
    char *input = tfgets(buf, LEN, stdin);
    if (input == NULL) {
        printf("nothing input\n");
    } else {
        printf("%s", input);
    }
    return 0;
}