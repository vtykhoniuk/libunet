#include "unet.h"


Action Signal(int signum, Action action)
{
    struct sigaction act, oldact;

    sigemptyset(&act.sa_mask);
    act.sa_handler = action;
    if (sigaction(signum, &act, &oldact) == -1)
        err_sys("sigaction error");

    return oldact.sa_handler;
}

