/*
** EPITECH PROJECT, 2022
** putstr
** File description:
** lib
*/

#include "../../include/mysh.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
