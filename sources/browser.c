/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** browser, path, env, pwd
*/

#include "../include/mysh.h"

int display_env(locker *test)
{
    int i = 0;

    while (test->envi[i]) {
        my_putstr(test->envi[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}

char *get_path(locker *test, char *str, int c)
{
    int i = 0, j = 0;
    char *keeper = NULL;

    while (test->envi[i] != NULL) {
        if (my_strncmp(test->envi[i], str, c) == 0) {
            keeper = malloc(1000);
            keeper = my_strdup(test->envi[i]);
        }
        i++;
    }
    return (keeper);
}

char *delete_path(locker *test, const char *s)
{
    int i = 0, j = 0, k = 0, m = 0;
    char *path = get_path(test, "PATH=", 5);
    char *keeper = NULL;

    if (path == NULL)
        return NULL;

    for (i = 0; path[i] != '='; i++);
    i++;
    m = i;
    for (k = 0; path[m] != '\0'; k++, m++);
    if (k != 0) {
        keeper = malloc(sizeof(char) * 1000);
        for (j = 0; path[i] != '\0'; i++, j++)
            keeper[j] = path[i];
        keeper[j] = '\0';
    }
    return (keeper);
}
