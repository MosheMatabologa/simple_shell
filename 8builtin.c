#include "shell.h"

/**
 * run_cmd - Function to execute a command or a pipeline
 * @cmd: Array of command and arguments
 * @cmd_count: Number of elements in the command array
 *
 * This function sets up pipes and forks to execute a command or a pipeline.
 * For a pipeline, it redirects standard input/output using pipe and dup2.
 *
 * Return: 0 on success, -1 on failure
 */
int run_cmd(char *cmd[], int cmd_count) {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return -1;
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
        if (cmd_count > 1) {
            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
        }

        if (execvp(cmd[0], cmd) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        if (cmd_count > 1) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
        }

        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
            return -1;
        }
    }

    return 0;
}

/**
 * parse_and_run_cmd - Function to parse and execute a command
 * @input: User input command string
 *
 * This function tokenizes the input command and executes it using run_cmd.
 * It tokenizes the input command using TOKEN_DELIM as delimiters.
 *
 * Return: 0 on success, -1 on failure
 */
int parse_and_run_cmd(char *input) {
    char *token;
    char *cmd[BUFFER_SIZE];
    int cmd_count = 0;

    token = strtok(input, TOKEN_DELIM);
    while (token != NULL) {
        cmd[cmd_count++] = token;
        token = strtok(NULL, TOKEN_DELIM);
    }

    cmd[cmd_count] = NULL;

    return run_cmd(cmd, cmd_count);
}

/**
 * main - Entry point of the shell program
 *
 * This function runs an infinite loop to read and execute commands entered by the user.
 * It displays a prompt, reads user input, and executes the command using parse_and_run_cmd.
 * The loop continues until the user enters 'exit'.
 *
 * Return: 0 on successful completion, 1 on failure
 */
int main() {
    char input[BUFFER_SIZE];

    while (1) {
        write(STDOUT_FILENO, "$ ", 2);
        ssize_t bytes_read = read(STDIN_FILENO, input, BUFFER_SIZE);

        if (bytes_read <= 0) {
            break;
        }

        input[bytes_read - 1] = '\0';

        if (strncmp(input, "exit\n", 5) == 0) {
            break;
        }

        if (parse_and_run_cmd(input) == -1) {
            perror("parse_and_run_cmd");
            return 1;
        }
    }

    return 0;
}

