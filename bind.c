#include "unet.h"

#include <sys/socket.h>

void Bind(int sockfd, SA *my_addr, socklen_t addrlen)
{
    if (bind(sockfd, my_addr, addrlen) != 0)
        err_sys("bind error");
}
