/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** redirect_utils
*/

#include "../include/mysh.h"

char *is_redirect_file(char **cmd, char *str)
{
    char *keeper = NULL;
    int i = 0;

    for (i = 0; cmd[i] != NULL; i++) {
        if (cmd[i + 1] != NULL && my_strcmp(str, ">") == 0) {
            cmd[i] = NULL;
            keeper = cmd[i + 1];
            cmd[i + 1] = NULL;
            return keeper;
        }
    }
    return NULL;
}
