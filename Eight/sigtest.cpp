#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid = getpid();
    cout << (int)pid << endl;
    int a[10];
    while(1) {
        for (int i = 0; i < 10; i++) {
            a[i] = 0;
        }
    }
}