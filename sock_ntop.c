#include "unet.h"

#include <arpa/inet.h>

#define INET_PORTSTRLEN 6
#define UNKNOWN_ERR_LEN 32
#define UNKNOWN_ERR     "Unknown address family"


static int sock_ntop(const SA *sa, char **pstr, int with_port)
{
    size_t pstrlen = 0;

    if (sa->sa_family == AF_INET || sa->sa_family == AF_INET6) {
        in_port_t port = 0;
        sa_family_t sa_family;
        const char *sin_addr = NULL;

        if (sa->sa_family == AF_INET) {
            const struct sockaddr_in *sin = (const struct sockaddr_in *) sa;
            port = sin->sin_port;
            pstrlen = INET_ADDRSTRLEN;
            sa_family = sin->sin_family;
            sin_addr = (const char *) &sin->sin_addr;
        } else {
            const struct sockaddr_in6 *sin = (const struct sockaddr_in6 *) sa;
            port = sin->sin6_port;
            sa_family = sin->sin6_family;
            pstrlen = INET6_ADDRSTRLEN;
            sin_addr = (const char *) &sin->sin6_addr;
        }

        if (with_port)
            pstrlen += INET_PORTSTRLEN+1;

        *pstr = malloc(pstrlen);
        memset(*pstr, 0, pstrlen);

        /* Consider inet_ntop error as non-fatal */
        if (inet_ntop(sa_family, sin_addr, *pstr, pstrlen) == NULL)
            return -1;

        if (with_port) {
            size_t n = strlen(*pstr);
            (*pstr)[n++] = ':';
            snprintf(*pstr+n, pstrlen - n, "%d", ntohs(port));
        }
    } else {
        *pstr = malloc(UNKNOWN_ERR_LEN);
        snprintf(*pstr, UNKNOWN_ERR_LEN, UNKNOWN_ERR ": [%d]", sa->sa_family);
    }

    return 0;
}


void Sock_ntop(const SA *sa, char **pstr)
{
    if (sock_ntop(sa, pstr, 1) == -1)
        err_sys("sock_ntop error");
}


void Sock_ntop_host(const SA *sa, char **pstr)
{
    if (sock_ntop(sa, pstr, 0) == -1)
        err_sys("sock_ntop error");
}
