/*shell.c file
* Definition of the functions:
* - execute_command
* - parse_input
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void execute_command(char *input){

    /*special command 'exit'*/
    if(strcmp(input, "exit") == 0){
        exit(0);
    }

    /*special command 'cd'*/
    if(strncmp(input, "cd ", 3) == 0){
        char *path = input + 3;
        if(chdir(path) != 0){
            perror("cd FAILED");
        }
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if(pid == 0){
        /*child start command*/
        char *args[64];
        parse_input(input, args);
        execvp(args[0], args);
        perror("execvp FAILED");
        exit(1);
    } else{
        /*parent wait for the child*/
        wait(NULL);
    }
}

void parse_input(char *input, char **args) {
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL) {
        args[++i] = strtok(NULL, " ");
    }
}