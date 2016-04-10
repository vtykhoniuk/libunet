#include "unet.h"

#include <sys/socket.h>

void Shutdown(int socket, int how)
{
    if (shutdown(socket, how) == -1)
        err_sys("shutdown error");
}
