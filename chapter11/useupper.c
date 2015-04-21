/*************************************************************************
	> File Name: useupper.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月21日 星期二 21时41分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char * argv[])
{
    char *filename;

    if(argc != 2)
    {
        fprintf(stderr,"Usage:useupper file\n");
        exit(1);
    }
    filename = argv[1];
    if(!freopen(filename,"r",stdin))
    {
        fprintf(stderr,"could not redirect stdin from file %s\n",filename);
        exit(2);
    }

    execl("./upper","upper",NULL);
    perror("could not exec ./upper");
    exit(3);
}
