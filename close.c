#include "unet.h"


void Close(int fd)
{
    if (close(fd) == -1)
        err_sys("write error");
}
