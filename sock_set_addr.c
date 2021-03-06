#include "unet.h"

#include <arpa/inet.h>

void Sock_set_addr(SA *sa, const char * restrict src)
{
    if (sa->sa_family == AF_INET) {
        struct sockaddr_in *sin = (struct sockaddr_in *) sa;
        Inet_pton(sin->sin_family, src, &sin->sin_addr);
    } else
        err_quit("Sock_set_addr error: unknown address family: %d", sa->sa_family);
}

void Sock_set_wild(SA *sa)
{
    if (sa->sa_family == AF_INET) {
        struct sockaddr_in *sin = (struct sockaddr_in *) sa;
        sin->sin_addr.s_addr = htonl(INADDR_ANY);
    } else if (sa->sa_family == AF_INET6) {
        struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) sa;
        sin6->sin6_addr = in6addr_any;
    } else
        err_quit("Sock_set_wild error: unknown address family: %d", sa->sa_family);
}
