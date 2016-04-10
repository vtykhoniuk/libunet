#include "unet.h"


void Fputs(const char *restrict s, FILE *restrict stream)
{
    if (fputs(s, stream) == -1)
        err_sys("fputs error");
}
