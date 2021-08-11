#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// #include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#define BUFFER_SIZE_MAX 1024
#define MESSAGE_SIZE_MAX 512

int main(int argc, char *argv[]) {
    // @state var int: ret is used as a detection signal during a function 
    //  call. 
    int ret = 0;

    // @state object int: If the function has been successfullly called, 
    //  client_socket will be used as file descriptor. 
    int client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if( client_socket < 0 ) {
        printf("Create socket faild.\n");
        exit(1);
    }


    // @state object struct sockaddr_un: This is AF_UNIX address.
    struct sockaddr_un client_address;
    bzero(&client_address, sizeof(client_address));
    client_address.sun_family = AF_UNIX;
    strcpy(client_address.sun_path, "./uds.socket");

    // unlink("./client.socket")

    // int opt = 1;
    // setsockopt(client_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // @call connect sys/socket.h: Try to connect server deamon.
    if( connect(client_socket, 
                (struct sockaddr *)&client_address, 
                sizeof(client_address) ) < 0 ) {
        printf("Can't connect to %s.\n", client_address.sun_path);
        exit(1);
    }

    char message[MESSAGE_SIZE_MAX+1];
    //@test print: Print message size when state.
    printf("[INFO] State %ld bytes message object.\n",sizeof(message));

    printf("Enter send message to server: ");
    scanf("%s",message);
    // @test print: Print message size.
    printf("[INFO] You enter %ld bytes message.\n",sizeof(message));

    if( write(client_socket, &message, sizeof(message)) ) {
        printf("[INFO] Send %ld bytes to server.\n",sizeof(message));
    }
    if( read(client_socket, &message, MESSAGE_SIZE_MAX+1) ) {
        printf("[server message]: %s .[%ld bytes]\n ",message, sizeof(message));
    }
    // char socket_file[MESSAGE_SIZE_MAX+1];
    // bzero(socket_file, MESSAGE_SIZE_MAX+1);

    // // printf("Please input file name on server:");
    // // scanf("%s", socket_file);

    // char buffer[BUFFER_SIZE_MAX];
    // bzero(bufer, BUFFER_SIZE_MAX);
    // strncpy(buffer, socket_file, strlen(socket_file)>BUFFER_SIZE_MAX ? BUFFER_SIZE_MAX:strlen(socket_file));

    // send(client_socket, buffer, BUFFER_SIZE_MAX, 0);
    // FILE *file_ptr = fopen("new", "w");
    // if(NULL == file_ptr) {
    //     printf("File %s can't open to write.\n",socket_file);
    //     exit(1);
    // }
    // bzero(buffer,BUFFER_SIZE_MAX);
    // int length = 0;
    // while( length=recv(client_socket,buffer,BUFFER_SIZE_MAX,0) ) {
    //     if( length < 0 ) {
    //         printf("Recieve data from server faild.\n");
    //         break;
    //     }
    //     int write_length = fwrite(buffer, sizeof(char), length, file_ptr);
    //     if(write_length < length) {
    //         printf("File %s write faild.\n", socket_file);
    //         break;
    //     }
    //     bzero(buffer, BUFFER_SIZE_MAX);
    // }
    // printf("Recieve file %s finished.\n");
    // close(file_ptr);

    close(client_socket);
    return 0;

}