/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** path
*/

#include "../../include/mysh.h"

int p_count_words(char *str)
{
    int i = 0, j = 1;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == ':' && str[i] != '\n')
            j++;
        i++;
    }
    return j;
}

char **str_to_array(locker *test, char *path)
{
    int x = 0, o = 0, j = 0, k = 0, word = 0;
    char **keeper = NULL;

    if (path == NULL) return NULL;
    word = p_count_words(path);
    keeper = malloc(sizeof(char *) * (word * 1000));
    for (o = 0; o < my_strlen(path); o++)
        keeper[o] = malloc(sizeof(char) * (my_strlen(path) * 2));
    for (x = 0; path[x] != '\0'; x++) {
        if (path[x] == ':') {
            keeper[k][j] = '\0';
            k++, j = 0;
        } else if (path[x]) {
            keeper[k][j] = path[x];
            j++;
        }
    } if (path[x - 1] != '\n') {
        keeper[k][j] = '\0';
        k++;
    } keeper[k] = NULL;
    return keeper;
}
