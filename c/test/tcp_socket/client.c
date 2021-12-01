#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[]) {
    int ret, sockfd;
    struct sockaddr_in server_sockaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        printf("[ERROR](%d):socket create socket object is error!\n");
        return -1;
    }

    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_sockaddr.sin_port = htons(9000);

    ret = connect(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr));
    if(ret < 0) {
        printf("[ERROR](%d) connect 127.0.0.1 is error!\n", ret);
        return -1;
    }

    printf("[DEBUG]: connect 127.0.0.1:9000 is successful!\n");

    close(sockfd);

    return 0;
}
