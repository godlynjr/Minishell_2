/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** execute_pipe
*/

#include "../include/mysh.h"

void pipe_path(char *keeper, char *pat, char **path, int i)
{
    keeper = malloc(sizeof(char) * 100);
    keeper = my_strcpy(keeper, path[i]);
    keeper[my_strlen(path[i]) + 1] = '\0';
    keeper = my_strcat(keeper, "/");
    keeper = my_strcat(keeper, pat);
}

void not_found(locker *test, char **cmd, char *pat)
{
    char *holder = delete_path(test, "PATH="), *keeper = NULL;
    char **path = str_to_array(test, holder);
    int i, j = 0, k = 0;

    for (i = 0; path[i] != NULL; i++) {
        pipe_path(keeper, pat, path, i);
        if (access(keeper, X_OK) == 0) {
            j = 1;
            break;
        }
    }
    if (my_strcmp(pat, "cd") == 0 || my_strcmp(pat, "setenv") == 0 ||
        my_strcmp(pat, "unsetenv") == 0 || my_strcmp(pat, "env") == 0)
        k = 1;
    if (j != 1 && k == 0) {
        my_putstr(cmd[1]);
        write(2, ": Command not found.\n", 21);
        test->not_found = 1;
    }
}

int my_pip2(locker *test, char **cmd, pid_t pid1, char *path)
{
    pid_t pid2 = 0;
    char *full_pa = malloc(1000), **keeper = str_to_tab(cmd[1]);

    waitpid(pid1, NULL, 0);
    pid2 = fork();
    dup2(test->fd[0], STDIN_FILENO);
    close(test->fd[0]);
    close(test->fd[1]);
    my_strcpy(full_pa, path);
    my_strcat(full_pa, keeper[0]);
    if (pid2 == 0) {
        if (execve(full_pa, keeper, NULL) == 0) return 1;
        else {
            not_found(test, cmd, keeper[0]);
            exit(0);
        }
    } else waitpid(pid2, NULL, 0);
    return 0;
}

int my_pipe(locker *test, char **cmd)
{
    pid_t pid1 = 0;
    int k = dup(0), g = dup(1);
    char **holder = str_to_tab(cmd[0]);
    char *full_p = malloc(1000), *path = "/bin/";

    if (invalid_pipe(cmd) == 1 || pipe(test->fd) == -1) return 1;
    pid1 = fork();
    if (pid1 < 0) return 1;
    if (pid1 == 0) {
        dup2(test->fd[1], STDOUT_FILENO);
        close(test->fd[0]);
        close(test->fd[1]);
        my_strcpy(full_p, path);
        my_strcat(full_p, holder[0]);
        execve(full_p, holder, NULL);
    } else if (cmd[1] && test->not_found == 0)
        execute_builtins(cmd[1], test->envi, test);
    dup2(k, 0), dup2(g, 1);
    return 0;
}
