#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/chat_socket"

int main() {
    int sock_fd;
    struct sockaddr_un addr;
    char buffer[100];

    // Create socket
    sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket address
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server!\n");

    // Communication loop
    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(sock_fd, buffer, strlen(buffer));

        memset(buffer, 0, sizeof(buffer));
        int n = read(sock_fd, buffer, sizeof(buffer) - 1);
        if (n == 0) {
            printf("Server disconnected\n");
            break;
        } else if (n == -1) {
            perror("read");
            break;
        }

        printf("Server: %s\n", buffer);
    }

    close(sock_fd);
    return 0;
}
