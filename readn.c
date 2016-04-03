#include "unet.h"

#include <unistd.h>


size_t Readn(int sockfd, void *buf, size_t n)
{
    ssize_t readn;
    char *ptr = buf;

    // Amount of bytes we have to read
    size_t nleft = n;

    while (nleft > 0)
        /* If we've read something from the socket, we would
           need just to update local counter 'nleft', and
           string pointer 'ptr' */
        if ((readn = read(sockfd, ptr, nleft)) > 0) {
            nleft -= readn;
            ptr += readn;
        }

        /* If there is nothing left to be read, just exit the
           loop */
        else if (readn == 0)
            break;

        /* For any error but EINTR we would print error message
           and terminate. The EINTR error means that the function
           has been interrupted by kernel. We would ignore that
           case and repeat the loop. */
        else if (errno != EINTR)
            err_sys("read error");

    return (n - nleft);
}
