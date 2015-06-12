/*************************************************************************
	> File Name: cinfo.c
	> Author: 
	> Mail: 
	> Created Time: 2015年06月12日 星期五 14时33分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
#ifdef DEBUG
    printf("Compiled: %s at %s\n",__DATE__,__TIME__);
    printf("This is line %d of file %s\n",__LINE__,__FILE__);
#endif
    printf("hello,world!\n");
    exit(0);
}
