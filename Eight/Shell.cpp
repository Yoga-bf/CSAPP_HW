#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


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
        cout << "> ";
        getline(cin, cc);
        memcpy(cmdline, cc.c_str(), cc.length());
        cout << cmdline << endl;
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

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return;
    if (!builtin_command(argv)) {
        if ((pid == fork()) == 0) {
            if (execve(argv[0], argv, environ) < 0) {
                cout << argv[0] << "Command not found.\n" << endl;
                exit(0);
            }
        }

        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                cout << "somewrong" << endl;
        }
        else
            cout << pid << " " << cmdline << endl;
    }
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit")){
        cout << "shell will quie" << endl;
        exit(0);
    }
        
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0;
}

int parseline(char *buf, char **argv)
{
    char *delim;
    int argc;
    int bg;

    buf[strlen(buf)-1] = ' ';
    cout << strlen(buf) << endl;
    while (*buf && (*buf == ' '))
        buf++;

    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 1;
    if ((bg = (*argv[argc-1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}