#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>


using namespace std;

void eval(char* cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

const int MAXLINE = 1024;
const int MAXARGS = 128;
int main()
{
    char cmdline[MAXLINE];
    string cc;
    while(1) {
        cout << "> " << endl;
        getline(cin, cc);
        memcpy(cmdline, cc.c_str(), cc.length());
        if(feof(stdin))
            exit(0);
    
        eval(cmdline);
    }
}

void eval(char* cmdline)
{
    char *argv[MAXARGS];
    char buf[MAXLINE];
    int bg;
    pid_t pid;
}