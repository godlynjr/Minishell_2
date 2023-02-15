/*
** EPITECH PROJECT, 2022
** B-PSU-200-COT-2-1-tetris-bridge.atindokpo
** File description:
** my_strcmp
*/

#include "../../include/mysh.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] == str2[i])
            i++;
    }
    return 0;
}
