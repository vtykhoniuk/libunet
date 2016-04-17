#include "unet.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

int tcp_connect(const char *host, const char *serv)
{
    int sockfd = -1;
    struct addrinfo *res, hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_flags = AI_CANONNAME;
    hints.ai_socktype = SOCK_STREAM;

    Getaddrinfo(host, serv, &hints, &res);

    struct addrinfo *r = res;
    do {
        sockfd = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
        if (sockfd == -1)
            continue;

        if (connect(sockfd, r->ai_addr, r->ai_addrlen) == 0)
            break;

        Close(sockfd);
    } while ((r = r->ai_next) != NULL);

    freeaddrinfo(res);

    return sockfd;
}
