/*************************************************************************
	> File Name: pipe1.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月26日 星期二 13时18分07秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];

    memset(buffer,'\0',sizeof(buffer));

    if(pipe(file_pipes) == 0)
    {
        data_processed = write(file_pipes[1],some_data,strlen(some_data));
        printf("Wrote %d bytes\n",data_processed);
        data_processed = read(file_pipes[0],buffer,BUFSIZ);
        printf("Read %d bytes: %s\n",data_processed,buffer);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
