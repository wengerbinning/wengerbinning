#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

// #include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#define BUFFER_SIZE_MAX 1033
#define MESSAGE_SIZE_MAX 1024

typedef struct {
    uint32_t msg_type;
    uint32_t msg_len;
    char data[MESSAGE_SIZE_MAX+1];
} mesg;

uint32_t len_string(const void* ptr) {
    int i = 0;
    if( ptr != NULL ) {
        while( *(char*)(ptr+i) != 0x00 ) {
            i++;
        }
    }
    return i;
}


int main(int argc, char *argv[]) {
    int ret = 0;
    int client_socket = socket(AF_UNIX, SOCK_DGRAM, 0);
    if( client_socket < 0 ) {
        printf("Create socket faild.\n");
        exit(1);
    }
    struct sockaddr_un client_address;
    bzero(&client_address, sizeof(client_address));
    client_address.sun_family = AF_UNIX;
    strcpy(client_address.sun_path, "/var/run/unix_domain_sg.sock");

    if( connect(client_socket, 
                (struct sockaddr *)&client_address, 
                sizeof(client_address) ) < 0 ) {
        printf("Can't connect to %s.\n", client_address.sun_path);
        exit(1);
    }

    mesg message;
    message.msg_type = htonl(17);
    int size = len_string(argv[1]);
    memset(message.data,0,MESSAGE_SIZE_MAX+1);
    strncpy(message.data,argv[1],size);
    message.msg_len = sizeof(message.data);
    message.msg_len = htonl(message.msg_len);
    if( write(client_socket, &message, sizeof(message)) ) {
        printf("[INFO] Send %ld bytes to server.\n",sizeof(message));
    }
    close(client_socket);
    return 0;

}