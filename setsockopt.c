#include "unet.h"

#include <sys/socket.h>

void Setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len)
{
    if (setsockopt(socket, level, option_name, option_value, option_len) == -1)
        err_sys("setsockopt error");
}
