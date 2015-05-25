/*************************************************************************
	> File Name: popen2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月25日 星期一 21时13分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *write_fp;
    char buffer[BUFSIZ+1];
    sprintf(buffer,"Once upon a time,there was...\n");
    write_fp=popen("od -c","w");
    if(write_fp != NULL)
    {
        fwrite(buffer,sizeof(char),strlen(buffer),write_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
