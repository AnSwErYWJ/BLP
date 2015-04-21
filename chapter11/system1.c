/*************************************************************************
	> File Name: system1.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月21日 星期二 21时03分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char * argv[])
{
    printf("Running ps with system\n");
    system("ps ax &");
    printf("Done.\n");
    exit(0);
}
