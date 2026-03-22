#ifndef MEMORY_H
#define MEMORY_H

#include "dsm.h"

extern char memory[MAX_PAGES][PAGE_SIZE];
extern int page_present[MAX_PAGES];

void init_memory();

#endif