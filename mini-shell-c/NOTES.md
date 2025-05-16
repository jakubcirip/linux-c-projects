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

fork() - create new process (child)
pid == 0 - for child (run execvp)
pid > 0 - for parent 
execvp() - replace child process by new process (for example ls)
wait() - parent process not running while until child stop

### In function parse_input(char *input, char **args):

Splits the input string (ls -l /home) into:
args[0] = "ls"
args[1] = "-l"
args[2] = "/home"
args[3] = NULL
This array is then used as an argument to execvp(), which expects it in the format argv[].

## Summary

The user enters a command (e.g. ls -l).
The shell uses fork() to create a child.
In the child, parse_input() is called to split the command.
Execvp() is run with the command and arguments.
If execvp() fails, an error is printed and the child terminates.
The parent waits() for the child to terminate.
