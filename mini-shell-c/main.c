/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT 1024

int main(){
    char input[MAX_INPUT];

    while(1){
        /*show prompt*/
        printf("jc-shell> ");
        fflush(stdout);

        /*read input*/
        if(fgets(input, sizeof(input), stdin) == NULL){
            perror("fgets FAILED");
            continue;
        }

        /*rm the char of the new line*/
        input[strcspn(input, "\n")] = 0;

        /*skip empty lines*/
        if(strlen(input) == 0)
            continue;

        /*input processing*/
        execute_command(input);
    }

    return 0;
}