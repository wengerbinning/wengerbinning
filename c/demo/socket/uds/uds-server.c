
// @description: This general include file. 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <string.h>

// @description: This standand module include file.
// #include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define LISTEN_QUENUE_MAX 10
#define BUFFER_SIZE_MAX 1024
#define MESSAGE_SIZE_MAX 512

int main(int argc, char *argv[]) {
    int ret =0;
    // @description: Create a unix domain socket.
    int server_socket = socket(PF_UNIX, SOCK_STREAM, 0);
    if( server_socket < 0 ) {
        printf("Create Socket failed!\n");
        exit(1);
    }
    
    // @test print server_socket.
    printf("Server Socket:%d.\n", server_socket);

    // @description: State a socket object to bind with socket.
    struct sockaddr_un server_address;
    bzero(&server_address, sizeof(server_address));
    //@description: AF_UNIX is socket file,AF_INET is port.
    server_address.sun_family = AF_UNIX;    
    strcpy(server_address.sun_path, "./uds.socket");

    // @explain unistd.h : 用于减少一次文件的链接数。in ording to delete file.
    unlink("./uds.socket");

    // @explain 
    // int opt = 1;
    // setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // @description: Bind socket and address.
    if( bind(server_socket,
        (struct sockaddr *)&server_address,
        sizeof(server_address) ) ) {
        printf("Server bind failed!\n");
        exit(1);
    }

    ret = listen(server_socket,LISTEN_QUENUE_MAX);
    if( ret < 0 ) {
        printf("Listen are faild!\n");
        exit(1);
    }

    while( 1 ) {
        struct sockaddr_in client_address;
        socklen_t address_size = sizeof(client_address);
        
        // @description: Accept client connect.
        int client_socket = accept(server_socket,(struct sockaddr *)&client_address, &address_size);
        if( client_socket < 0 ) {
            printf("Server accept failed!\n");
            break;
        }

        char buffer[BUFFER_SIZE_MAX];
        bzero(buffer, BUFFER_SIZE_MAX);
        
        // @description: receive client message.
        ret = recv(client_socket, buffer, BUFFER_SIZE_MAX, 0);
        if(ret <0) {
            printf("Server recieve data faild!\n");
            break;
        }

        char message[MESSAGE_SIZE_MAX+1];
        bzero(message, MESSAGE_SIZE_MAX+1);
        
        strncpy(message, buffer, strlen(buffer));
        printf("[client message]: %s.\n", message);
        
        // FILE *file = fopen(socket_file, "r");

        // if( NULL == file ) {
        //     printf("File: %s not found.\n",socket_file);
        // } else {
        //     bzero(buffer, BUFFER_SIZE_MAX);
        //     int message_size = 0;
        //     message_size = fread(buffer, sizeof(char), BUFFER_SIZE_MAX, file);
        //     if(message_size > 0) {
        //         printf("message size: %d\n", message_size);
        //         if( send(client_socket, buffer, message_size,0) < 0 ) {
        //             printf("Send %s faild!\n",socket_file);
        //             break;
        //         }
        //         fclose(file);
        //         printf("File %s transfer finshed.\n",socket_file);
        //     }
        //     close(client_socket);
        //     return 0;
        // }

        close(client_socket);
        return 0;
    }

}