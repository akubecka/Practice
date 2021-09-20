/*I pledge my honor that I have abided by the Stevens Honor System.
Alex Kubecka
April 3, 2019
CS 392 Assignment 3
The cs392_shell.c function 
*/

#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"
#include <stdlib.h>

int MAX_SIZE = 256*sizeof(char);//Allocate memory

//Allocates memory and splits input into seperate strings
char** comSplit(char* input,int readLength){
   int commands = 1;
    for(int i=0; input[i] != '\0'; i++){ //to end of string
        if(input[i] == ' '){ //If there is a space increment commands
            commands++;
        }
    }
    char** str = malloc(MAX_SIZE); //Dynamically allocate memory for arrays
    for(int i=0; i<commands; i++){
        str[i] = malloc(commands * sizeof(char));//Give enough memory for character total
    }
    char* ptr = strtok(input, " ");//get elements before space
    int index = 0;
    while(ptr != NULL){//Find the end of the string
        strcpy(str[index], ptr);
        ptr = strtok(NULL, " ");
        index++;
    }
    str[index] = NULL; //Set end of array to null
    
    return str;
}

int main(int argc, char ** argv){
    char input[MAX_SIZE];
    int lineLen;
    
    while(1){
        register_sig(); //Call the signal handler
        printf("cs392_shell $: ");
        fflush(stdout); // Adds new line after command is handled

        lineLen = read(0, input, MAX_SIZE-1);
        if(lineLen < 0){
            if(errno == EINTR){
                continue;    
            }else{
                perror("Error reading command.\n");
                exit(1);
            }
        }
        input[lineLen-1] = '\0';

    log1(input);

    char** arr = comSplit(input,lineLen); //split input 
    
    int execNum = exec1(arr); //create int that returns integer that exec returns
    //if(strcmp(arr, "exit")==0){
    //    exit(1);
    //}
    if(execNum == 0){//If no errors then continue
        for(int i=0; arr[i]!=NULL; i++){
            free(arr[i]);
        }
        free(arr);//free memory
    } else if(execNum == 1){//if user types exit, end the program
        printf("Exiting\n");
        for(int i=0; arr[i]!=NULL; i++){
            free(arr[i]);
        }
        free(arr);
        exit(0);
    } else if(execNum == 2){//Return an error
        perror("An error occurred.\n");
        for(int i=0; arr[i]!=NULL; i++){
            free(arr[i]);
        }
        free(arr);
        exit(1);
    } else if(execNum == 3){//If user types in the wrong command
        printf("This command was not found.\n");
        for(int i=0; arr[i]!=NULL; i++){
            free(arr[i]);
        }
        free(arr);
        exit(1);
    }else{//Else an error
        printf("An error occurred.\n");
        for(int i=0; arr[i]!=NULL; i++){
            free(arr[i]);
        }
        free(arr);
        exit(1);
        }
    }

    return 0;
}