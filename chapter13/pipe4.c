/*************************************************************************
	> File Name: pipe4.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月26日 星期二 21时04分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor;
    memset(buffer,'\0',sizeof(buffer));
    sscanf(argv[1],"%d",&file_descriptor);
    data_processed = read(file_descriptor,buffer,BUFSIZ);

    printf("%d - read %d bytes: %s \n",getpid(),data_processed,buffer);
    exit(EXIT_SUCCESS);
}
