/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** unset_env
*/

#include "../include/mysh.h"

char **my_arr_cpy(char **tab)
{
    int i = 0, j = 0;
    char **keeper = malloc(10000);

    for (i = 0, j = 0; tab[i] != NULL; i++, j++)
        keeper[j] = tab[i];
    keeper[j] = NULL;
    return keeper;
}

void unset_env(locker *test, char **cmd)
{
    int i = 0, j = 0, k = 0, m = 0;
    char **new_env = malloc(10000);
    char *keeper = malloc(sizeof(strlen(cmd[1]) + 1));

    my_strcpy(keeper, cmd[1]);
    my_strcat(keeper, "=");
    for (k = 0, m = 0; test->envi[k] != NULL; k++) {
        if (my_strncmp(test->envi[k], keeper, my_strlen(keeper)) != 0) {
            new_env[m] = test->envi[k];
            m++;
        }
    }
    new_env[m] = NULL;
    test->envi = my_arr_cpy(new_env);
}
