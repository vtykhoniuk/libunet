#include "unet.h"

int tcp_listen(const char *host, const char *serv)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /* A value for setsockopt
    */
    const int reuse_addr = 1;

    struct addrinfo *res;
    int error;
    if ((error = getaddrinfo(host, serv, &hints, &res)) == -1)
        err_quit("tcp_listen error for host [%s] service [%s]: %s", host, serv, gai_strerror(error));

    int sockfd;
    struct addrinfo *r = res;
    do {
        if ((sockfd = socket(r->ai_family, r->ai_socktype, r->ai_protocol)) == -1)
            continue;

        Setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr));
        if (bind(sockfd, r->ai_addr, r->ai_addrlen) == 0)
            break;

        Close(sockfd);
    } while ((r = r->ai_next) != NULL);

    /* We iterate though all addrinfo list and couldn't either
       create a socket or bind. Print out latest sys error and
       exit
       */
    if (r == NULL)
        err_sys("tcp_listen error for host [%s] service [%s]", host, serv);

    freeaddrinfo(res);

    if (listen(sockfd, 10) == -1)
        err_sys("tcp_listen error for host [%s] service [%s]", host, serv);

    return sockfd;
}
