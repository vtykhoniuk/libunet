#include "unet.h"

#include <arpa/inet.h>

void Sock_set_port(SA *sa, uint16_t port)
{
    if (sa->sa_family == AF_INET) {
        struct sockaddr_in *sin = (struct sockaddr_in *) sa;
        sin->sin_port = htons(port);
    } else
        err_quit("sock_set_addr error: unknown address family: %d", sa->sa_family);
}
