/*************************************************************************
	> File Name: ctrlc2.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月21日 星期二 21时55分54秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n",sig);
   // (void)signal(SIGINT,SIG_DFL);
}

int main(int argc,const char * argv[])
{
   // (void) signal(SIGINT,ouch);

    struct sigaction act;
    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGINT,&act,NULL);
    while(1)
    {
        printf("hello world!\n");
        sleep(1);
    }
}
