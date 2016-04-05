#include "unet.h"

/* fork
   */
#include <unistd.h>

pid_t Fork()
{
    pid_t pid = fork();
    if (pid < 0)
        err_sys("fork error");

    return pid;
}

