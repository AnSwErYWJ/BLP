/*************************************************************************
> File Name: fork2.c
> Author:AnSwEr 
> Mail:yuanweijie1993@gmail.com 
> Created Time: 2015年04月21日 星期二 21时18分10秒
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc,const char * argv[])
{
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");
    pid=fork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n=3;
            break;
        default:
            message = "This is teh parent";
            n=5;
            break;
    }

    for(;n>0;n--)
    {
        puts(message);
        sleep(1);
    }
    exit(0);
}
