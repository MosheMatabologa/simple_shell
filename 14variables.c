#include "shell.h"

/**
 * replace_variables - Function to replace $$ and $? in the command
 * @command: Command string to replace variables in
 * @last_status: Status of the last executed command
 *
 * This function replaces occurrences of "$$" with the process ID and "$?" 
 * with the status of the last executed command in the given command string.
 *
 * Return: Pointer to the string with replaced variables
 */
char *replace_variables(char *command, int last_status) 
{
    char pid_str[20]; // To hold the process ID as string
    char status_str[20]; // To hold the status as string
    char *result = (char *)malloc(MAX_COMMAND_LENGTH);

    if (!result) {
        perror("Memory allocation error");
        _exit(EXIT_FAILURE);
    }

    memset(result, 0, MAX_COMMAND_LENGTH);

    while (*command != '\0') {
        if (command[0] == '$' && command[1] == '$') {
            int pid = getpid();
            snprintf(pid_str, sizeof(pid_str), "%d", pid);
            strncat(result, pid_str, sizeof(pid_str));
            command += 2; // Move past $$
        } else if (command[0] == '$' && command[1] == '?') {
            snprintf(status_str, sizeof(status_str), "%d", last_status);
            strncat(result, status_str, sizeof(status_str));
            command += 2; // Move past $?
        } else {
            strncat(result, command++, 1);
        }
    }
    return result;
}

/**
 * main - Entry point of the program
 *
 * This function runs an infinite loop, taking user input, and replaces variables 
 * ($$ and $?) in the entered command. It then displays the processed command.
 * The loop continues until an error or EOF is encountered.
 *
 * Return: Always 0 on successful completion
 */
int main()
{
    int last_status = 0;

    while (1) {
        // Replace $$ and $? in the command
        char command[MAX_COMMAND_LENGTH];
        write(STDOUT_FILENO, "$ ", 2); // Display prompt
        ssize_t read_bytes = read(STDIN_FILENO, command, sizeof(command));

        if (read_bytes <= 0)
        {
            break; // Exit on error or EOF
        }

        command[read_bytes - 1] = '\0'; // Replace newline with null terminator

        // Process the command and replace variables
        char *processed_command = replace_variables(command, last_status);

        // Use the processed command for execution
        // ...

        // For demonstration, printing the processed command
        write(STDOUT_FILENO, "Processed command: ", strlen("Processed command: "));
        write(STDOUT_FILENO, processed_command, strlen(processed_command));
        write(STDOUT_FILENO, "\n", 1);

        // Free allocated memory
        free(processed_command);
    }

    return 0;
}
