#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

int is_page_present(int page);
void set_page_present(int page);
void invalidate_page(int page);

#endif