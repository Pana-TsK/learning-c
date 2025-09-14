#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define CHUNK_SIZE 1024

int main(void) {

    int server_fd, client_fd;
    struct sockaddr_in addr;

    char buffer[CHUNK_SIZE];

    FILE * fptr;
    size_t n_read;
    
    // create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket error");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 1);

    socklen_t addrlen = sizeof(addr);
    client_fd = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
    if (!client_fd) {
        perror("error finding client");
        return -1;
    }

    // open the file
    fptr = fopen("server_file.csv", "rb");
    if (!fptr) {
        perror("error opening file");
    }

    while((n_read = fread(buffer, 1, CHUNK_SIZE, fptr)) > 0) {
        send(client_fd, buffer, n_read, 0);
    }

    fclose(fptr);
    close(server_fd);
    close(client_fd);

    return 0;
}