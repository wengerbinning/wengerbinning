#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFERSIZE 1024

int main(int argc, const char *argv[]) {
    int ret, listen_sockfd, conn_sockfd;
    struct sockaddr_in listen_sockaddr, conn_sockaddr;
    socklen_t conn_addr_len;
    pid_t pid;
    char buffer[BUFFERSIZE];

    listen_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_sockfd < 0) {
        printf("[ERROR](error code: %d) create socket is error!\n", listen_sockfd);
        return -1;
    }

    bzero(&listen_sockaddr, sizeof(listen_sockaddr));
    listen_sockaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &listen_sockaddr.sin_addr);
    listen_sockaddr.sin_port = htons(9001);

    ret = bind(listen_sockfd, (struct sockaddr *)&listen_sockaddr, sizeof(listen_sockaddr));
    if(ret < 0) {
        printf("[ERROR](error code: %d) bind socket to socket address is failed.\n");
        return -1;
    }

    ret = listen(listen_sockfd, 5);
    if(ret < 0) {
        printf("[ERROR](error code:%d) listening socket address is faild.\n", ret);
        return -1;
    }

    while(1) {
        conn_addr_len = sizeof(conn_sockaddr);
        conn_sockfd = accept(listen_sockfd, (struct sockaddr *)&conn_sockaddr, &conn_addr_len);
        if(conn_sockfd < 0) {
            printf("[ERROR](error code:%d) accpet is error!\n", conn_sockfd);
            continue;
        }
        pid = fork();
        if(pid == 0) {
            close(listen_sockfd);
            printf("[DEBUG] this sub process's pid is %d\n", getpid());
            read(conn_sockfd, buffer, sizeof(buffer)-1);
            printf("%s\r\n",buffer);
            exit(0);
        }

    }

    return 0;
}
