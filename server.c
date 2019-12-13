#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void run(char* host, int port) {
    int serverSockFd, recvLen;
    socklen_t clientLen;
    char recv_data[1024];
    char *flag="Abbflagis{lz4r4TnD}\n";
    if ((serverSockFd=socket(AF_INET, SOCK_DGRAM, 0))<0){
        error("ERROR opening socket");
    }
    struct sockaddr_in serverAddr, clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port=htons(port);
    if (bind(serverSockFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr))<0){
        error("ERROR on binding");
    }
    while(1){
        clientLen=sizeof(clientAddr);
        if ((recvLen=recvfrom(serverSockFd, recv_data, 1024, 0, (struct sockaddr *) &clientAddr, &clientLen))<0){
            error("ERROR on accept");
        }
        sendto(serverSockFd, (char *)flag, strlen(flag), 0, (struct sockaddr *) &clientAddr, clientLen);
    }
    close(serverSockFd);
}

int main (int argc, char** argv){
    if(argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    char* host = argv[1];
    int port = atoi(argv[2]);
    printf("Starting server on %s:%d\n", host, port);
    run(host, port);
    return 0;
}