#ifndef UNET_H
#define UNET_H

/* Almost every function needs to process at least
   a system error */
#include "cerror.h"

/* For size_t
   */
#include <stddef.h>

/* For struct sockaddr_in
   */
#include <netinet/in.h>

typedef struct sockaddr SA;

size_t readn(int sockfd, void *buf, size_t n);
void writen(int sockfd, const void *buf, size_t n);
char *sock_ntop(const SA *sa);

int Socket(int domain, int type, int protocol);
void Bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
char *Sock_ntop(const SA *sa);

#endif // UNET_H
