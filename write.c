#include "unet.h"

#include <sys/types.h>
#include <sys/uio.h>

size_t Write(int fildes, void *buf, size_t nbyte)
{
    ssize_t n;

AGAIN:
    if ((n = write(fildes, buf, nbyte)) < 0) {
        if (errno == EINTR)
            goto AGAIN;
        else
            err_sys("write error");
    }

    return n;
}
