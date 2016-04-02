#include "unet.h"

// For 'read' call
#include <unistd.h>


void Writen(int sockfd, const void *buf, size_t n)
{
    ssize_t written;
    const char *ptr = buf;

    while (n > 0)
        if ((written = write(sockfd, ptr, n)) >= 0) {
            n -= written;
            ptr += written;
        } else if (errno != EINTR)
            err_sys("write error");
}
