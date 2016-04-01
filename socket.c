#include "unet.h"

int Socket(int domain, int type, int protocol)
{
    int sockfd = socket(domain, type, protocol);
    if (sockfd == -1)
        err_sys("Error openning socket");

    return sockfd;
}
