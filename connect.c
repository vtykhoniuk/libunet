#include "unet.h"

#include <sys/types.h>
#include <sys/socket.h>

void Connect(int socket, const SA *address, socklen_t address_len)
{
    if (connect(socket, address, address_len) == -1)
        err_sys("connect error");
}
