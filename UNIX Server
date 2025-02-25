#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/unix_socket"

int main() {
    int srv_socket, cli_socket;
    struct sockaddr_un srv_address, cli_address;
    socklen_t cli_addr_len;
    char msg_buffer[256];

    srv_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (srv_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    srv_address.sun_family = AF_UNIX;
    strcpy(srv_address.sun_path, SOCKET_PATH);
    unlink(SOCKET_PATH); // Remove if the file exists

    if (bind(srv_socket, (struct sockaddr*)&srv_address, sizeof(srv_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(srv_socket, 5);
    printf("Server listening on UNIX socket...\n");

    cli_addr_len = sizeof(cli_address);
    cli_socket = accept(srv_socket, (struct sockaddr*)&cli_address, &cli_addr_len);
    if (cli_socket == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(msg_buffer, 0, sizeof(msg_buffer));
        read(cli_socket, msg_buffer, sizeof(msg_buffer));
        printf("Client: %s\n", msg_buffer);
        if (strcmp(msg_buffer, "exit") == 0) break;

        printf("Server: ");
        fgets(msg_buffer, sizeof(msg_buffer), stdin);
        write(cli_socket, msg_buffer, strlen(msg_buffer));
    }

    close(cli_socket);
    close(srv_socket);
    unlink(SOCKET_PATH);
    return 0;
}
