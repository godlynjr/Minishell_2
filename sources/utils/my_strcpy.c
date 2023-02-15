/*
** EPITECH PROJECT, 2022
** B-PSU-200-COT-2-1-tetris-bridge.atindokpo
** File description:
** my_strcpy
*/

#include "../../include/mysh.h"

char *my_strcpy(char *dest, char const *src)
{
    int shift = 0;

    while (src[shift] != '\0') {
        dest[shift] = src[shift];
        shift++;
    }
    dest[shift] = '\0';
    return (dest);
}
