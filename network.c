#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "memory.h"
#include "page_table.h"

void start_server(int port) {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);

    printf("Server listening on port %d...\n", port);

    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        int request[2]; // [type, page]
        read(client_socket, request, sizeof(request));

        int type = request[0];
        int page = request[1];

        if (type == 1) {
            printf("Page request for %d\n", page);
            write(client_socket, memory[page], PAGE_SIZE);
        } else if (type == 2) {
            printf("Invalidate page %d\n", page);
            invalidate_page(page);
        }

        close(client_socket);
    }
}

void request_page(int page, int port) {
    int sock;
    struct sockaddr_in serv_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    int request[2] = {1, page};
    write(sock, request, sizeof(request));

    read(sock, memory[page], PAGE_SIZE);
    set_page_present(page);

    printf("Received page %d\n", page);

    close(sock);
}

void send_invalidation(int page, int port) {
    int sock;
    struct sockaddr_in serv_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    int request[2] = {2, page};
    write(sock, request, sizeof(request));

    close(sock);
}