#include <stdio.h>
#include <time.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, const char * argv[]) {
    int ret=0, listen_sockfd, conn_sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in server_sockaddr, client_sockaddr;
    time_t ticks;
    listen_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if( listen_sockfd < 0 ) {
        printf("[ERROR](%d): server create socket was failed.\n", listen_sockfd);
        return -1;
    }
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_sockaddr.sin_port = htons(0);

    ret = bind(listen_sockfd, (struct sockaddr*)&server_sockaddr, sizeof(server_sockaddr));
    if(ret < 0) {
        printf("[ERROR](%d): server has bound socket to sockaddr was failed.\n", ret);
        return -1;
    }
    
    ret = listen(listen_sockfd, 5);
    if(ret < 0) {
        printf("[ERROR](%d): server listen sockaddr was failed.\n", ret);
        return -1;
    }
    
    while(1) {
        conn_sockfd = accept(listen_sockfd, (struct sockaddr*)&client_sockaddr, (socklen_t*)sizeof(client_sockaddr));
        if(conn_sockfd < 0) {
            printf("[ERROR](%d): accept error: code:\n", conn_sockfd);
            continue;
        }
        printf("[INFO] found a connection from %s:%d\n",
               inet_ntop(AF_INET,&client_sockaddr.sin_addr,buffer, sizeof(buffer)),
               ntohs(client_sockaddr.sin_port));

        ticks =time(NULL);
        snprintf(buffer, sizeof(buffer), "%.24s\r\n", ctime(&ticks));
        write(conn_sockfd, buffer, strlen(buffer));
        close(conn_sockfd);

    }

    return 0;
}