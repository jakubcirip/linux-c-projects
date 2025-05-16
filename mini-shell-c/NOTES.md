# All notes about files in this folder

## main.c

#define MAX_INPUT 1024 - definition of max input size

fflush(stdout) - checking if there are any data in the buffer (stdout) and if so, then write the data to the OS

if(fgets(input, sizeof(input), stdin) == NULL){
            perror("fgets FAILED");
            continue;
        }
        - if input == NULL, write error message

input[strcspn(input, "\n")] = 0; - remove the char of the new line

if(strlen(input) == 0)
            continue;
            - will skip empty lines

execute_command(input); - input processing

## shell.c

### In function execute_command(char *input):

strcmp(input, "exit") == 0 - compare input with 'exit'
    - if it's true, exit mini-shell

if(strncmp(input, "cd ", 3) == 0) - compare the first 3 characters of both strings

char *path = input + 3; - set path from input

if(chdir(path) != 0){
            perror("cd FAILED");
        }
    - chdir(path) - system call function that is used to change the current working directory (as an alias for shell cd) by specified path
    - chdir retur 0 on success, -1 for error

pid_t pid = fork(); 
pid_t - type of a process id (unsigned)
