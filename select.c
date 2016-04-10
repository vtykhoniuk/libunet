#include "unet.h"


int Select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout)
{
    int r = select(nfds, readfds, writefds, errorfds, timeout);

    if (r == -1)
        err_sys("select error");

    return r;
}
