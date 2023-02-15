/*
** EPITECH PROJECT, 2022
** bootcamp
** File description:
** lib
*/

#include "../../include/mysh.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
