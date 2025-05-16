/*shell.h file
* Declaration of the functions:
* - execute_command
* - parse_input
*/

#ifndef SHELL_H
#define SHELL_H

void execute_command(char *input);
void parse_input(char *input, char **args);

#endif