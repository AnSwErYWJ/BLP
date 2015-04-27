/*************************************************************************
	> File Name: getdate.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月27日 星期一 10时29分59秒
 ************************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    char *host;
    int sockfd;
    int len,result;
    struct sockaddr_in address;
    struct hostent *hostinfo;
    struct servent *servinfo;
    char buffer[128];

    if(argc == 1)
        host = "localhost";
    else
        host=argv[1];
    /*查询主机的地址，如果找不到，就报告一条错误*/
    hostinfo = gethostbyname(host);
    if(!hostinfo)
    {
        fprintf(stderr,"no host:%s\n",host);
        exit(1);
    }
    /*检查主机上是否有daytime服务*/
    servinfo = getservbyname("daytime","tcp");
    if(!servinfo)
    {
        fprintf(stderr,"no daytime service\n");
        exit(2);
    }
    printf("daytime port is %d\n",ntohs(servinfo -> s_port));
    /*创建一个套接字*/
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    /*构造connect调用要使用的地址*/
    address.sin_family = AF_INET;
    address.sin_port = servinfo -> s_port;
    address.sin_addr = *(struct in_addr *)*hostinfo -> h_addr_list;
    len = sizeof(address);
    /*然后建立连接并取得有关的信息*/
    result = connect(sockfd,(struct sockaddr *)&address,len);
    if(result == -1)
    {
        perror("oops:getdate");
        exit(3);
    }
    result = read(sockfd,buffer,sizeof(buffer));
    buffer[result] = '\0';
    printf("read %d bytes: %s",result,buffer);

    close(sockfd);
    exit(0);
}
