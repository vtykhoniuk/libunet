#include "unet.h"

#include <arpa/inet.h>

void Sock_set_addr(SA *sa, uint32_t addr)
{
    if (sa->sa_family == AF_INET) {
        struct sockaddr_in *sin = (struct sockaddr_in *) sa;
        sin->sin_addr.s_addr = htonl(addr);
    } else
        err_quit("sock_set_addr error: unknown address family: %d", sa->sa_family);
}
