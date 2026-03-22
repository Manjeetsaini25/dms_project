#include "network.h"

extern int OTHER_PORT;

void invalidate_others(int page) {
    send_invalidation(page, OTHER_PORT);
}