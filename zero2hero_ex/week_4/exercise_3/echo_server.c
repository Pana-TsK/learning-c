#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> // socket type
#include <arpa/inet.h> // make available in_addr structure
#include <unistd.h>

#define PORT 8080
 
int main(void) {

    int server_fd, newsocket;
    struct sockaddr_in address;

    socklen_t addr_len = sizeof(address);
    char buffer[1024];
    char server_message[] = "Hello, I'm the server!\n";
    int valread; // length of the value read


    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("error with socket");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("error binding the port");
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        return -1;
    }

    if ((newsocket = accept(server_fd, (struct sockaddr *)&address, &addr_len)) < 0) {
        perror("error accepting connection");
        return -1;
    }

    valread = recv(newsocket, buffer, 1024-1, 0);
    buffer[valread] = '\0';
    printf("%s", buffer);

    send(newsocket, server_message, strlen(server_message), 0);
    printf("server message sent. \n");

    close(newsocket);
    close(server_fd);
    
    return 0;
}