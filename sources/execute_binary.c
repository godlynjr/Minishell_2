/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** execute_binary
*/

#include "../include/mysh.h"

int binary_type(locker *test, char **cmd, char **env)
{
    if (!access(cmd[0], X_OK) && !opendir(cmd[0])
        && cmd[0][0] == '.' && cmd[0][1] == '/') {
        forker(cmd[0], cmd, env);
        return 0;
    }
    else if ((cmd[0][0] == '.' && cmd[0][1] == '/') ||
             (opendir(cmd[0]) != 0)) {
        my_putstr(cmd[0]);
        my_putstr(": Permission denied.\n");
        return 1;
    }
    return 0;
}
