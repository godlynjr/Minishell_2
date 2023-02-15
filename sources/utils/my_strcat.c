/*
** EPITECH PROJECT, 2022
** B-PSU-200-COT-2-1-tetris-bridge.atindokpo
** File description:
** my_strcat
*/

#include "../../include/mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int len1 = my_strlen(dest);

    while (src[x]) {
        dest[len1 + x] = src[x];
        x++;
    }
    dest[len1 + x] = '\0';
    return (dest);
}
