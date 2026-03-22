#include "memory.h"

char memory[MAX_PAGES][PAGE_SIZE];
int page_present[MAX_PAGES];

void init_memory() {
    for (int i = 0; i < MAX_PAGES; i++) {
        page_present[i] = 0;
    }
}