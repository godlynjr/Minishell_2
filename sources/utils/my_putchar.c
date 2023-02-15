/*
** EPITECH PROJECT, 2022
** putchar
** File description:
** lib
*/

#include "../../include/mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
