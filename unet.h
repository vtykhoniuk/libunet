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

/* For signal constants */
#include <signal.h>

#define MAXLINE 1024

typedef struct sockaddr SA;
typedef void (*Action)(int);

char *sock_ntop(const SA *sa);
ssize_t readline(int fd, char *buf, size_t buflen);

size_t Readn(int sockfd, void *buf, size_t n);
void Writen(int sockfd, const void *buf, size_t n);
int Socket(int domain, int type, int protocol);
void Bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
char *Sock_ntop(const SA *sa);
void Close(int fd);
void Sock_set_addr(SA *sa, uint32_t addr);
void Sock_set_wild(SA *sa);
void Sock_set_port(SA *sa, uint16_t port);
size_t Readline(int fd, char *buf, size_t buflen);
pid_t Fork();
Action Signal(int signum, Action action);

#endif // UNET_H
