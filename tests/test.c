/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/mysh.h"

int keep = 6;

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


// I'm not sharing that with you just yet :)
