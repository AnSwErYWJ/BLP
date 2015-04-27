/*************************************************************************
	> File Name: select.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月27日 星期一 15时06分30秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    char buffer[128];
    int result,nread;

    fd_set inputs,testfds;
    struct timeval timeout;

    FD_ZERO(&inputs);
    FD_SET(0,&inputs);
    /*在标准输入stdin上最多等待2.5s*/
    while(1)
    {
        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;

        result = select(FD_SETSIZE,&testfds,(fd_set *)NULL,(fd_set *)NULL,&timeout);
        /*如果没有输入，程序将再次循环。如果出现一个错误，程序将退出运行*/
        switch(result)
        {
            case 0:
                printf("timeout\n");
                break;
            case -1:
                perror("select");
                exit(1);
            default:
                if(FD_ISSET(0,&testfds))
                {
                    ioctl(0,FIONREAD,&nread);
                    if(nread == 0)
                    {
                        printf("keyboard done\n");
                        exit(0);
                    }
                    nread = read(0,buffer,nread);
                    buffer[nread] = 0;
                    printf("read %d from keyboard:%s",nread,buffer);
                }
            break;
        }
    }
}
