/*I pledge my honor that I have abided by the Stevens Honor System.
Alex Kubecka
April 3, 2019
CS 392 Assignment 3
The cs392_signal.h function 
*/

#ifndef CS392_SIGNAL_H
#define CS392_SIGNAL_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sig_handler(int, siginfo_t*, void*);
void register_sig();


#endif