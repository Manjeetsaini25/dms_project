#ifndef DSM_H
#define DSM_H

#define PAGE_SIZE 256
#define MAX_PAGES 10

void dsm_init(int node_id);
char read_memory(int page, int offset);
void write_memory(int page, int offset, char value);

#endif