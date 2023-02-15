/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** env
*/

#include "../include/mysh.h"

int nb_lines_env(char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++);
    return i;
}

void add_newline_1(locker *test, char *str1, char *str2)
{
    int a = my_strlen(str1) + my_strlen(str2), i = 0, j = 0;
    char *holder = malloc(sizeof(char) * (a + 3));
    char **new_env = malloc(10000);

    my_strcpy(holder, str1);
    my_strcat(holder, "=");
    my_strcat(holder, str2);
    for (i = 0, j = 0; test->envi[i] != NULL; i++, j++)
        new_env[j] = test->envi[i];
    new_env[j] = holder;
    new_env[j + 1] = NULL;
    test->envi = my_arr_cpy(new_env);
}

void add_newline_2(locker *test, char *str1)
{
    int a = my_strlen(str1), i = 0, j = 0;
    char *holder = malloc(sizeof(char) * (a + 3));
    char **new_env = malloc(10000);

    my_strcpy(holder, str1);
    my_strcat(holder, "=");
    for (i = 0, j = 0; test->envi[i] != NULL; i++, j++)
        new_env[j] = test->envi[i];
    new_env[j] = holder;
    new_env[j + 1] = NULL;
    test->envi = my_arr_cpy(new_env);
}
