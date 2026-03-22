#include <stdio.h>
#include "memory.h"

void print_memory() {
    printf("Memory State:\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        if (page_present[i]) {
            printf("Page %d: %c\n", i, memory[i][0]);
        }
    }
}