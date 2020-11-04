#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

static void handler(int signum){
    if(signum == SIGINT){
        printf("\nError occurred. Wrapping...\nClosing...\n");
        exit(0);
    }
    return;
}

int main(){
    struct sigaction var;
    var.sa_handler = handler;

    sigaction(SIGINT, &var, NULL);

    for(int i=0;;i++){}
}