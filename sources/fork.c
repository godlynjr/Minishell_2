/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** fork
*/

#include "../include/mysh.h"

void get_line(char *buff, size_t bufsize, locker *test)
{
    ssize_t keeper = getline(&buff, &bufsize, stdin);

    if (keeper == -1) {
        my_putstr("exit\n");
        exit(0);
    }
}

void forker(char *path, char **argv, char **env)
{
    pid_t pid = 0;
    pid_t pol;
    pid = fork();

    if (pid == -1)
        exit(84);
    if (pid == 0) {
        execve(path, argv, env);
        exit(0);
    } else
        wait(&pol);
}
