#ifndef UNET_H
#define UNET_H

/* Almost every function needs to process at least
   a system error */
#include "cerror.h"

/* For size_t
   */
#include <stddef.h>

/* For error codes
*/
#include <errno.h>

/* For socket
   */
#include <sys/socket.h>

size_t readn(int sockfd, void *buf, size_t n);
void writen(int sockfd, const void *buf, size_t n);

int Socket(int domain, int type, int protocol);

#endif // UNET_H
