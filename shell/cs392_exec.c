/*I pledge my honor that I have abided by the Stevens Honor System.
Alex Kubecka
April 3, 2019
CS 392 Assignment 3
The cs392_exec.c function 
*/

#include "cs392_exec.h"

int exec1(char** args){
    pid_t cpid;
    if(strcmp(args[0],"exit")==0){//If the user types exit, return 1
        return 1;
    }

    cpid=fork();

    if(cpid < 0){
        return 2;
    }else if(cpid>0){
        wait(NULL);
    }else if(cpid==0){//Child process
        if(execvp(args[0], args) < 0){
            return 3;
        }
    }
    
    return 0;
}