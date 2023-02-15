/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** cleaner
*/

#include "../../include/mysh.h"

char *rm_space(char *str)
{
    int i = 0, j = 0, k = 0, m = 0;
    char *keeper = malloc(sizeof(char) * (my_strlen(str) * 10000));

    for (i = 0; str[i] == ' '; i++);
    for (; i <= my_strlen(str); i++) {
        if (str[i] == ' ')
            i++;
        for (; str[i] != ' ' && str[i] != '\0'; i++, j++)
            keeper[j] = str[i];
    }
    keeper[j] = '\0';
    return keeper;
}

char *rm_tab(char *str)
{
    int i = 0, j = 0, k = 0, m = 0;
    char *keeper = malloc(sizeof(char) * (my_strlen(str) * 10000));

    for (i = 0; str[i] == '\t'; i++);
    for (; i <= my_strlen(str); i++) {
        if (str[i] == '\t')
            i++;
        for (; str[i] != '\t' && str[i] != '\0'; i++, j++)
            keeper[j] = str[i];
    }
    keeper[j] = '\0';
    return keeper;
}
