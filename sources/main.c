/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "../include/mysh.h"
#include "../include/mysh_2.h"

void fill(locker *test, char **env)
{
    test->error = 0;
    test->envi = new_env(env);
    test->line = nb_lines_env(env);
    test->apk = 0;
    test->cd = 0;
    test->column = 0;
    test->nb_column = 1;
    test->no_direct = 0;
    test->holder = malloc(3);
    test->fd = malloc(3);
    test->fd_file = malloc(2);
    test->fd_file2 = malloc(2);
    test->not_found = 0;
}

int main(int ac, char **av, char **env)
{
    locker test;
    int a = 0;

    fill(&test, env);
    if (ac != 1)
        return 84;
    else
        parse_line(env, &test);
    return a;
}
