/*************************************************************************
	> File Name: main.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月13日 星期一 21时41分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"a.h"
extern void fun_two();
extern void fun_three();
int main(int argc,const char * argv[])
{
    printf("1\n");
    fun_two();
    fun_three();
    exit(0);
}
