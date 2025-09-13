#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char * argv[]) {
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;

    char message[] = "Hello from the client.\n";
    char buffer[1024];

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("error creating socket");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if(status = connect(client_fd, (struct sockaddr*) & serv_addr, sizeof(serv_addr))) {
        perror("error with connecting");
        return -1;
    }

    send(client_fd, message, strlen(message), 0);
    printf("Hello message sent\n");
    valread = read(client_fd, buffer,
                   1024 - 1); 
    printf("%s\n", buffer);

    // closing the connected socket
    close(client_fd);
    return 0;
}