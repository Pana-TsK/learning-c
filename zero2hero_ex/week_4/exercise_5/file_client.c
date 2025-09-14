#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define CHUNK_SIZE 1024

int main(void) {

    int client_fd;

    char buffer[CHUNK_SIZE];

    struct sockaddr_in addr;
    
    FILE * fptr;
    size_t n_read;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (!client_fd) {
        perror("socket error");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("error connecting");
        return -1;
    }

    fptr = fopen("received_file.csv", "wb");
    if (!fptr) {
        perror("error opening file");
        return -1;
    }

    while((n_read = recv(client_fd, buffer, CHUNK_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n_read, fptr);
    }

    fclose(fptr);
    close(client_fd);

    return 0;
}
