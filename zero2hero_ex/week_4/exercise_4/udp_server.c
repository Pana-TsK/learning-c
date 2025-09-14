#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 5000
#define MAXLINE 1024

int main(void) {
    char buffer[MAXLINE];
    char message[] = "Pong: Server\n";

    int listenfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    int n;

    // Create a UDP socket
    if ((listenfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind server address to socket descriptor
    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    // Receive datagram
    len = sizeof(cliaddr);
    n = recvfrom(listenfd, buffer, sizeof(buffer) - 1, 0,
                 (struct sockaddr*)&cliaddr, &len);
    if (n < 0) {
        perror("recvfrom failed");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("Client: %s", buffer);

    // Send response
    if (sendto(listenfd, message, strlen(message), 0,
               (struct sockaddr*)&cliaddr, len) < 0) {
        perror("sendto failed");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    printf("Pong sent back to client\n");

    close(listenfd);
    return 0;
}
