#include "unet.h"

#include <arpa/inet.h>

void Inet_pton(int af, const char * restrict src, void * restrict dst)
{
    int r;

    if ((r = inet_pton(af, src, dst)) <= 0) {
        if (r == -1)    err_sys("inet_pton error");
        else            err_quit("Inet_pton error: address [%s] is not parseable", src);
    }
}
