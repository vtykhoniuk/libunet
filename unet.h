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

/* fd_set, timeval */
#include <sys/select.h>

/* struct FILE */
#include <stdio.h>

/* memset */
#include <string.h>

/* exit */
#include <stdlib.h>

/* Bunch of low level syscalls like
   read, write, fork, close
   */
#include <unistd.h>

#include <netdb.h>

#define MAXLINE 1024

typedef struct sockaddr SA;


size_t Read(int fd, void *buf, size_t n);
size_t Write(int fd, void *buf, size_t n);
size_t Readn(int fd, void *buf, size_t n);
void Writen(int fd, const void *buf, size_t n);
ssize_t readline(int fd, char *buf, size_t buflen);
size_t Readline(int fd, char *buf, size_t n);

int tcp_connect(const char *host, const char *serv);
int tcp_listen(const char *host, const char *serv);

int Socket(int domain, int type, int protocol);
void Bind(int sockfd, SA *addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, SA *addr, socklen_t *addrlen);
void Connect(int sockfd, const SA *addr, socklen_t addrlen);
void Close(int fd);
void Shutdown(int sockfd, int how);
size_t Recvfrom(int sockfd, void *restrict buffer, size_t length, int flags, SA *restrict addr, socklen_t *restrict addrlen);
size_t Sendto(int sockfd, const void *buffer, size_t length, int flags, const SA *addr, socklen_t addrlen);
void Getaddrinfo(const char *hostname, const char *servname, const struct addrinfo *hints, struct addrinfo **res);
void Setsockopt(int sockfd, int level, int option_name, const void *option_value, socklen_t option_len);

void Sock_ntop(const SA *sa, char **pstr);
void Sock_ntop_host(const SA *sa, char **pstr);
void Inet_pton(int af, const char * restrict src, void * restrict dst);
void Sock_set_addr(SA *sa, const char * restrict src);
void Sock_set_wild(SA *sa);
void Sock_set_port(SA *sa, uint16_t port);

pid_t Fork();
typedef void (*Action)(int);
Action Signal(int signum, Action action);

int Select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);
void Fputs(const char *restrict s, FILE *restrict stream);

#endif // UNET_H
