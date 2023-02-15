/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** my_strncmp
*/

#include "../../include/mysh.h"

int my_strncmp(char *str1, char *str2, int c)
{
    int i = 0;

    while ((str1[i] != '\0' || str2[i] != '\0') && i < c) {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] == str2[i])
            i++;
    }
    return 0;
}
