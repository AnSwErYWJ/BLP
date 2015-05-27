/*************************************************************************
	> File Name: fifo1.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年05月27日 星期三 18时12分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    int res = mkfifo("/tmp/my_fifo",0777);
    if(res == 0)
    printf("FIFO created\n");
    exit(EXIT_SUCCESS);
}
