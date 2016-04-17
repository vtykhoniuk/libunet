#include "unet.h"

#include <sys/types.h>
#include <sys/socket.h>

void Getaddrinfo(const char *hostname, const char *servname, const struct addrinfo *hints, struct addrinfo **res)
{
    int r = getaddrinfo(hostname, servname, hints, res);
    if (r != 0)
        err_sys(gai_strerror(r));
}
