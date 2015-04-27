/*************************************************************************
	> File Name: server4.c
	> Author:AnSwEr 
	> Mail:yuanweijie1993@gmail.com 
	> Created Time: 2015年04月26日 星期日 20时22分20秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>

int main(int argc,char *argv[])
{
    int server_sockfd,client_sockfd;
    int server_len,client_len;
    //struct sockaddr_un server_address;
    //struct sockaddr_un client_address;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    /*删除以前的套接字，为服务器创建一个未命名的套接字*/
    unlink("server_sockfd");
    //server_sockfd = socket(AF_UNIX,SOCK_STREAM,0);
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    /*命名套接字*/
    //server_address.sun_family = AF_UNIX;
    //strcpy(server_address.sun_path,"server_socket");
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
    /*创建一个连接队列，开始等待客户进行连接*/
    listen(server_sockfd,5);
    signal(SIGCHLD,SIG_IGN);
    while(1)
    {
        char ch;
        printf("server waiting!\n");
        /*接受一个连接*/
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
        /*通过fork调用为这个客户创建一个子进程，然后测试你是在父进程还是子进程*/
        if(fork() == 0)
        {
        /*对client_sockfd套接字上的客户进行读写*/
        read(client_sockfd,&ch,1);
        sleep(5);
        ch++;
        write(client_sockfd,&ch,1);
        close(client_sockfd);
        exit(0);
        }
        else
            close(client_sockfd);
    }
    // return 0;
}
