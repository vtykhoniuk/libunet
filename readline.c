#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "unet.h"

static char rlbuf[MAXLINE];
static char *rlptr;
static size_t rlcnt;

static ssize_t _read(int fd, char *c)
{
    if (rlcnt == 0) {
again:
        rlptr = rlbuf;
        ssize_t rc = read(fd, &rlbuf, MAXLINE);

        if (rc > 0)                 rlcnt = rc;
        else if (rc == 0)           return 0;
        else if (errno == EINTR)    goto again;
        else                        return -1;
    }

    *c = *rlptr;
    ++rlptr;
    --rlcnt;

    return 1;
}

ssize_t readline(int fd, char *buf, size_t buflen)
{
    size_t n = buflen;
    char *ptr = buf;

    while (n > 1) {
        char c;
        ssize_t rc = _read(fd, &c);

        if (rc == 1) {
            *ptr++ = c;
            n--;
            if (c == '\n')
                break;
        } else if (rc == 0)
            break;
        else
            return -1;
    }

    *ptr = '\0';

    return (buflen - n);
}

size_t Readline(int fd, char *buf, size_t buflen)
{
    ssize_t n = readline(fd, buf, buflen);

    if (n == -1)
        err_sys("readline error:");

    return n;
}
