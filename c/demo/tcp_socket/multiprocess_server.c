#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

    listen_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_sockfd < 0) {
        printf("[ERROR] Create socket is error!\n");
        return -1;
    }

    bzero(&listen_sockaddr, sizeof(listen_sockaddr));
    listen_sockaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &listen_sockaddr.sin_addr);
    listen_sockaddr.sin_port = htons(9000);

    ret = bind(listen_sockfd, (struct sockaddr *)&listen_sockaddr, sizeof(listen_sockaddr));
    if(ret < 0) {
        printf("[ERROR] Bind socket to socket address is failed.\n");
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
            char *buffer= malloc(BUFFERSIZE);
            int err,sockfd = conn_sockfd;
            struct sockaddr_in sockaddr = conn_sockaddr;
            bzero(buffer, BUFFERSIZE);
            err = read(sockfd,buffer, sizeof(buffer));
            if(err < 0) {
                printf("[INFO] client was lost!\n");
                free(buffer);
                close(sockfd);
                exit(0);
            }

            printf("from %s:%d message: %s\n",
                   inet_ntoa(sockaddr.sin_addr),
                   ntohs(sockaddr.sin_port),
                   buffer
                   );
            write(sockfd, buffer, sizeof(buffer));
        }
    }

    return 0;
}
