/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** execute_env
*/

#include "../include/mysh.h"

int is_alpha_num(char *string)
{
    int i = 0;

    if (string[0] >= 'A' && string[0] <= 'Z' ||
        string[0] >= 'a' && string[0] <= 'z');
    else
        return 2;
    for (i = 0; string[i]; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z' ||
            string[i] >= 'a' && string[i] <= 'z' ||
            string[i] >= '0' && string[i] <= '9');
        else
            return 1;
    }
    return 0;
}

char **new_env(char **env)
{
    int i = 0, j = 0;
    char **keeper = malloc(100000);

    for (i = 0, j = 0; env[i] != NULL; i++, j++)
        keeper[j] = my_strdup(env[i]);
    keeper[j] = NULL;
    return keeper;
}

char **dealer_env(locker *test, char **cmd, char **env)
{
    if (my_strcmp(cmd[0], "env") == 0 && !cmd[1] ||
        my_strcmp(cmd[0], "setenv") == 0 && !cmd[1])
        display_env(test);
    if ((my_strcmp(cmd[0], "setenv") == 0) && cmd[1]) {
        if (cmd[3])
            write(2, "setenv: Too many arguments.\n", 29);
        else if (!cmd[3])
            set_env(test, cmd);
    }
    if ((my_strcmp(cmd[0], "unsetenv") == 0)) {
        if (!cmd[1])
            write(2, "unsetenv: Too few arguments.\n", 30);
        else
            unset_env(test, cmd);
    }
}
