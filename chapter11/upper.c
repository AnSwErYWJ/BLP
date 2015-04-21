/*************************************************************************
	> File Name: upper.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月21日 星期二 21时37分56秒
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc,const char * argv[])
{
    int ch;
    while((ch=getchar()) != EOF)
        putchar(toupper(ch));
    exit(0);
}

