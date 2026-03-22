#ifndef NETWORK_H
#define NETWORK_H

void start_server(int port);
void request_page(int page, int port);
void send_invalidation(int page, int port);

#endif