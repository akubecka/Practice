/*I pledge my honor that I have abided by the Stevens Honor System.
Alex Kubecka
April 3, 2019
CS 392 Assignment 3
The cs392_signal.c function 
*/

#include "cs392_signal.h"


void sig_handler(int signo, siginfo_t *siginfo, void* context){
    if(signo == SIGINT){//Handler for SIGINT
        printf("Received SIGINT\n");
    }
    
    if(signo == SIGTSTP){//Handler for SIGTSTP
        printf("Received SIGTSTP\n");
    }
}

void register_sig(){
    struct sigaction act;
    memset(&act, '\0', sizeof(act));

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT, &act, NULL) < 0){
        perror("sigaction");
    }
    if(sigaction(SIGTSTP, &act, NULL) < 0){
        perror("sigaction");
    }

}

