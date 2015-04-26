/*************************************************************************
	> File Name: client2.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月26日 星期日 20时11分38秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
    int sockfd;
    int len;
    // struct sockaddr_un address;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    /*为客户创建一个套接字*/
    //sockfd = socket(AF_UNIX,SOCK_STREAM,0);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    /*根据服务器的情况给套接字命名*/
    //address.sun_family = AF_UNIX;
    //strcpy(address.sun_path,"server_socket");
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(9734);
    len = sizeof(address);
    /*将我们的套接字连接到服务器的套接字*/
    result = connect(sockfd,(struct sockaddr *)&address,len);

    if(result == -1)
    {
        perror("oops:client1");
        exit(1);
    }
    /*通过sockfd进行读写操作*/
    write(sockfd,&ch,1);
    read(sockfd,&ch,1);
    printf("char from server = %c\n",ch);
    close(sockfd);
    exit(0);
    return 0;
}
