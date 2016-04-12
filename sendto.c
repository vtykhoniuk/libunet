#include "unet.h"

#include <sys/socket.h>


size_t Sendto(int socket, const void *buffer, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len)
{
    ssize_t n = sendto(socket, buffer, length, flags, dest_addr, dest_len);

    if (n == -1)
        err_sys("sendto error");

    return n;
}
