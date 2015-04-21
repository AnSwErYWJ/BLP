/*************************************************************************
> File Name: wait.c
> Author:AnSwEr 
> Mail:yuanweijie1993@gmail.com 
> Created Time: 2015年04月21日 星期二 21时18分10秒
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,const char * argv[])
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid=fork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n=5;
            exit_code = 37;
            break;
        default:
            message = "This is teh parent";
            n=3;
            exit_code = 0;
            break;
    }

    for(;n>0;n--)
    {
        puts(message);
        sleep(1);
    }
    
    if(pid != 0)
    {
        int stat_val;
        pid_t child_pid;

        child_pid=wait(&stat_val);

        printf("Child has finished:PID = %d\n",child_pid);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    exit(exit_code);
}
