#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024

int main(int argc, const char *argv[]) {
    int ret, sockfd;
    struct sockaddr_in server_sockaddr, local_sockaddr;
    socklen_t local_addr_len;
    char buffer[BUFFERSIZE];

    // creat a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        printf("[ERROR](%d):socket create socket object is error!\n", sockfd);
        return -1;
    }

    // connect server to 127.0.0.1:9000.
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_sockaddr.sin_port = htons(9000);

    ret = connect(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr));
    if(ret < 0) {
        printf("[ERROR](%d) connect 127.0.0.1 is error!\n", ret);
        return -1;
    }

    // get local socket address information.
    local_addr_len = sizeof(local_sockaddr);
    ret = getsockname(sockfd, (struct sockaddr *)&local_sockaddr, &local_addr_len);
    if(ret < 0) {
        printf("[ERROR](%d) get local socker address is error!\n", ret);
        return -1;
    }

    printf("[DEBUG]: client pid id %d, socker address is %s:%d\n",
           getpid(),
           inet_ntoa(local_sockaddr.sin_addr),
           ntohs(local_sockaddr.sin_port));

    printf("[INFO]: connect 127.0.0.1:9000 is successful!\n");

    // TODO you can do something that tell service.
    while(1) {
        bzero(&buffer, sizeof(buffer));
        scanf("%s\n", buffer);
        if( 0 == memcpy(buffer, "quit", sizeof("quit")) ) {
            break;
        }

        write(sockfd, buffer, sizeof(buffer));
        read(sockfd, buffer, sizeof(buffer)-1);
        printf("%s", buffer);
    }

    // close socket.
    close(sockfd);

    return 0;
}
