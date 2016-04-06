#include "unet.h"

#include <string.h>

Action Signal(int signo, Action action)
{
    struct sigaction act, oldact;
    memset(&act, 0, sizeof(act));

    sigemptyset(&act.sa_mask);
    act.sa_handler = action;
    if (signo != SIGALRM)
        act.sa_flags |= SA_RESTART;

    if (sigaction(signo, &act, &oldact) == -1)
        err_sys("sigaction error");

    return oldact.sa_handler;
}
