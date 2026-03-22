#include <stdio.h>
#include "dsm.h"
#include "memory.h"
#include "page_table.h"
#include "network.h"
#include "consistency.h"

int NODE_ID;
int OTHER_PORT;

void dsm_init(int node_id) {
    NODE_ID = node_id;
    init_memory();

    if (node_id == 1) {
        OTHER_PORT = 5001;
        set_page_present(0);
        memory[0][0] = 'A';
    } else {
        OTHER_PORT = 5000;
        set_page_present(1);
        memory[1][0] = 'B';
    }
}

char read_memory(int page, int offset) {
    if (!is_page_present(page)) {
        printf("Page fault on page %d\n", page);
        request_page(page, OTHER_PORT);
    }
    return memory[page][offset];
}

void write_memory(int page, int offset, char value) {
    if (!is_page_present(page)) {
        printf("Page fault on page %d\n", page);
        request_page(page, OTHER_PORT);
    }

    memory[page][offset] = value;

    // Invalidate other copies
    invalidate_others(page);
}