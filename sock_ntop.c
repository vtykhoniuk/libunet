#include "unet.h"

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INET_PORTSTRLEN 6

char *sock_ntop(const SA *sa)
{
    char *str = NULL;

    if (sa->sa_family == AF_INET) {
        const struct sockaddr_in *sin = (const struct sockaddr_in *) sa;
        char addrstr[INET_ADDRSTRLEN];
        char portstr[INET_PORTSTRLEN];

        /* Consider inet_ntop error as non-fatal */
        if (inet_ntop(AF_INET, &sin->sin_addr, addrstr, INET_ADDRSTRLEN) == NULL)
            err_sys("inet_ntop error");

        size_t addrlen = strlen(addrstr);
        int portlen = snprintf(portstr, INET_PORTSTRLEN, "%d", ntohs(sin->sin_port));
        size_t strlen = addrlen + portlen + 2;
        str = malloc(strlen);
        snprintf(str, strlen, "%s:%s", addrstr, portstr);
    } else
        err_ret("sock_ntop error: unknown AF_xxx: %d", sa->sa_family);

    return str;
}
