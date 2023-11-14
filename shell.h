#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

// Constants
#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

// Function prototypes
int run_cmd(char *cmd[], int cmd_count);
int parse_and_run_cmd(char *input);
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int status, int idx);
void exit_shell(char **command, int status);
void print_env(char **command, int status);

#endif /* MAIN_H */
