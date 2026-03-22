CC=gcc
CFLAGS=-lpthread

all:
	$(CC) main.c dsm.c memory.c page_table.c network.c consistency.c utils.c -o dsm $(CFLAGS)