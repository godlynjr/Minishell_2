/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "../include/mysh.h"
#include "../include/mysh_2.h"

int is_inside(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int check_manipulations(locker *test, char **env, char *buff)
{
    int i = 0;
    char **keeper = NULL;

    if (is_inside(buff, '|') == 1) {
        keeper = str_array(buff, '|');
        test->fd[2];
        my_pipe(test, keeper);
        return 1;
    }
    if (is_inside(buff, '>') == 1) {
        keeper = str_array(buff, '>');
        my_redirect_out(test, keeper, env);
        return 1;
    }
    if (is_inside(buff, '<') == 1) {
        keeper = str_array(buff, '<');
        my_redirect_in(test, keeper, env);
        return 1;
    }
    return 0;
}

void check_commands(locker *test, char **env, char *buff, size_t bufsize)
{
    if (check_manipulations(test, env, buff) != 0) {
        return;
    }
    shell(buff, bufsize, env, test);
}

void shell(char *buff, size_t bufsize, char **env, locker *test)
{
    int a = 0;

    if (my_strcmp(buff, "\n") == 0 && my_strlen(buff) == 1)
        mysh(buff, bufsize, env, test);
    if (my_strcmp(rm_space(buff), "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    } else {
        a = execute_builtins(buff, env, test);
        test->error = a;
    }
}

int mysh(char *buff, size_t bufsize, char **env, locker *test)
{
    while (1) {
        test->column = 0;
        if (isatty(0) != 0)
            prompt();
        signal(SIGINT, SIG_IGN);
        get_line(buff, bufsize, test);
        buff = browse_buff(buff);
        check_column(test, buff);
        nb_column(test, buff);
        separator(test, buff, env);
    }
}
