/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** invalid
*/

#include "../include/mysh.h"

int invalid_pipe(char **cmd)
{
    if (!cmd[1]) {
        my_putstr("Invalid null command.\n");
        return 1;
    }
    return 0;
}

int invalid_redirect(char **cmd)
{
    if (!cmd[1]) {
        my_putstr("Missing name for redirect.\n");
        return 1;
    }
    return 0;
}
