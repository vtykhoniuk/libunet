#include "unet.h"

#include <sys/socket.h>


size_t Recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len)
{
    ssize_t n = recvfrom(socket, buffer, length, flags, address, address_len);

    if (n == -1)
        err_sys("recvfrom error");

    return n;
}
