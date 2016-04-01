#include "unet.h"

#include <sys/socket.h>

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int fd = accept(sockfd, addr, addrlen);

    if (fd == -1)
        err_sys("accept error");

    return fd;
}
