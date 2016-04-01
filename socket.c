#include "unet.h"

#include <sys/socket.h>

int Socket(int domain, int type, int protocol)
{
    int sockfd = socket(domain, type, protocol);
    if (sockfd == -1)
        err_sys("socket error");

    return sockfd;
}
