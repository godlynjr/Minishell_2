/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** my_strdup
*/

#include "../../include/mysh.h"

char *my_strdup(char *str)
{
    int i = 0, j = 0;

    char *keeper = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        keeper[j] = str[i];
        i++;
        j++;
    }
    keeper[j] = '\0';
    return keeper;
}
