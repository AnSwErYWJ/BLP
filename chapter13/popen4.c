/*************************************************************************
	> File Name: popen4.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月25日 星期一 21时46分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *read_fp;
    int chars_read;
    char buffer[BUFSIZ+1];

    memset(buffer,'\0',sizeof(buffer));
    read_fp = popen("cat popen*.c|wc -l","r");
    if(read_fp != NULL)
    {
        chars_read = fread(buffer,sizeof(char),BUFSIZ,read_fp);
        while(chars_read > 0)
        {
            buffer[chars_read-1] = '\0';
            printf("Reading:-\n %s\n",buffer);
            chars_read = fread(buffer,sizeof(char),BUFSIZ,read_fp);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
