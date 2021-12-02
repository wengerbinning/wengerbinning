#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 2048

int main(int argc, const char * argv[]) {
    int ret, listen_sockfd, conn_sockfd;
    struct sockaddr_in listen_sockaddr, conn_sockaddr;
    socklen_t conn_addr_len = 0;
    char buffer[MAXLINE];
    time_t ticks;
    
    listen_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if( listen_sockfd < 0 ) {
        printf("[ERROR](%d): server create listening socket was failed.\n", listen_sockfd);
        return -1;
    }

    memset(&listen_sockaddr, 0, sizeof(listen_sockaddr));
    listen_sockaddr.sin_family = AF_INET;
    listen_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    listen_sockaddr.sin_port = htons(9000);

    ret = bind(listen_sockfd, (struct sockaddr*)&listen_sockaddr, (socklen_t)sizeof(listen_sockaddr));
    if(ret < 0) {
        printf("[ERROR](%d): server has bound socket to sockaddr was failed.\n", ret);
        return -1;
    }
    
    ret = listen(listen_sockfd, 5);
    if(ret < 0) {
        printf("[ERROR](%d): server listen sockaddr was failed.\n", ret);
        return -1;
    }
    printf("[DEBUG]:This service's pid is %d\n",getpid());
    printf("[INFO]: This TCP Socket service is running in %s:%d ...\n",
           inet_ntoa(listen_sockaddr.sin_addr),
           ntohs(listen_sockaddr.sin_port));
    
    while(1) {
        memset(&conn_sockaddr, 0, sizeof(conn_sockaddr));
        conn_addr_len = sizeof(conn_sockaddr);
        conn_sockfd = accept(listen_sockfd, (struct sockaddr *)&conn_sockaddr, &conn_addr_len);
        if(conn_sockfd < 0) {
            printf("[ERROR](%d): accept is error!\n", conn_sockfd);
             continue;
        }
        printf("[INFO] found a connection from %s:%d\n", 
               inet_ntoa(conn_sockaddr.sin_addr),
               ntohs(conn_sockaddr.sin_port));

        // TODO you can do something that reply connection client.
        read(conn_sockfd, buffer, sizeof(buffer)-1);
        printf("%s\n", buffer);
//        snprintf(buffer, sizeof(buffer)-1, "Hi, I'm server!\n");
//        write(conn_sockfd, buffer, sizeof(buffer));

          
    }

    return 0;
}
