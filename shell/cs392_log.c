/*I pledge my honor that I have abided by the Stevens Honor System.
Alex Kubecka
April 3, 2019
CS 392 Assignment 3
The cs392_log.c function 
*/

#include "cs392_log.h"

void log1(char* args){
    FILE *fp=fopen("cs392_shell.log", "a"); // opens or creates the file and opens
    if(fp == NULL){
        printf("Cannot open file due to error. %d\n", errno);
        exit(1);
    }else{
        fprintf(fp, "%s\n", args);
    }
    fclose(fp);
}