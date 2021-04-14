#include <stdio.h>

void f(void);

int y = 100;
int x = 200;

int main()
{
    f();
    printf("x is 0x%x\ny is 0x%x\n", x, y);
}