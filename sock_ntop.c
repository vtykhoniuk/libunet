#include "unet.h"

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

#define INET_PORTSTRLEN 6
#define UNKNOWN_ERR_LEN 32
#define UNKNOWN_ERR     "Unknown address family"

char *sock_ntop(const SA *sa)
{
    char *str = NULL;

    if (sa->sa_family == AF_INET) {
        const struct sockaddr_in *sin = (const struct sockaddr_in *) sa;
        char addrstr[INET_ADDRSTRLEN];
        char portstr[INET_PORTSTRLEN];

        /* Consider inet_ntop error as non-fatal */
        if (inet_ntop(AF_INET, &sin->sin_addr, addrstr, INET_ADDRSTRLEN) == NULL)
            return NULL;

        size_t addrlen = strlen(addrstr);
        int portlen = snprintf(portstr, INET_PORTSTRLEN, "%d", ntohs(sin->sin_port));
        size_t strlen = addrlen + portlen + 2;
        str = malloc(strlen);
        snprintf(str, strlen, "%s:%s", addrstr, portstr);
    } else {
        str = malloc(UNKNOWN_ERR_LEN);
        snprintf(str, UNKNOWN_ERR_LEN, UNKNOWN_ERR ": [%d]", sa->sa_family);
    }

    return str;
}

char *Sock_ntop(const SA *sa)
{
    char *str = sock_ntop(sa);

    if (str == NULL)
        err_sys("sock_ntop error");

    return str;
}
