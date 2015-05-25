/*************************************************************************
	> File Name: popen3.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月25日 星期一 21时26分56秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
int main()
{
    FILE *read_fp;
    char buffer[MAX+1];
    int chars_read;
    memset(buffer,'\0',sizeof(buffer));
    read_fp=popen("ps ax","r");
    if(read_fp != NULL)
    {
        chars_read = fread(buffer,sizeof(char),MAX,read_fp);
        while(chars_read > 0)
        {
            buffer[chars_read - 1]='\0';
            printf("Reading %d:-\n %s\n",MAX,buffer);
            chars_read = fread(buffer,sizeof(char),MAX,read_fp);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
