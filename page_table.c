#include "memory.h"

int is_page_present(int page) {
    return page_present[page];
}

void set_page_present(int page) {
    page_present[page] = 1;
}

void invalidate_page(int page) {
    page_present[page] = 0;
}