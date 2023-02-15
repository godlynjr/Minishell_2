/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** exec_redirect_out
*/

#include "../include/mysh.h"

int my_redirect_out(locker *test, char **cmd, char **env)
{
    char *file = NULL;
    int k = dup(0), g = dup(1);

    if (invalid_redirect(cmd) == 1) return 1;
    file = rm_space(cmd[1]);
    file = rm_tab(file);
    test->fd_file[0] = open(file, (O_CREAT | O_RDWR | O_TRUNC), 00700);
    if (test->fd_file[0] == -1) {
        my_putstr(strerror(errno));
        return 1;
    }
    dup2(test->fd_file[0], 1);
    execute_builtins(cmd[0], env, test);
    close(test->fd_file[0]);
    dup2(k, 0);
    dup2(g, 1);
    return 0;
}
