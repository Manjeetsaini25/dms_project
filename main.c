#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "dsm.h"
#include "network.h"
#include "utils.h"

void* server_thread(void* arg) {
    int port = *(int*)arg;
    start_server(port);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./dsm <node_id>\n");
        return 1;
    }

    int node_id = atoi(argv[1]);
    int port = (node_id == 1) ? 5000 : 5001;

    dsm_init(node_id);

    pthread_t tid;
    pthread_create(&tid, NULL, server_thread, &port);

    sleep(2);

    printf("Reading page 1...\n");
    char val = read_memory(1, 0);

    printf("Value = %c\n", val);

    write_memory(1, 0, 'X');

    print_memory();

    pthread_join(tid, NULL);

    return 0;
}