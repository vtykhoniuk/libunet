#include "unet.h"

#include <sys/socket.h>

void Listen(int sockfd, int backlog)
{
    if (listen(sockfd, backlog) < 0)
        err_sys("listen error");
}
