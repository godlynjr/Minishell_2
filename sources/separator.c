/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** separator
*/

#include "../include/mysh.h"
#include "../include/mysh_2.h"

void separator(locker *test, char *buff, char **env)
{
    size_t bufsize = 200;
    char **mul_buf = NULL;
    char **cmd = str_to_tab(buff);
    int i = 0;

    if (test->column == 0)
        check_commands(test, env, buff, bufsize);
    if (test->column == 1) {
        mul_buf = str_array(buff, ';');
        for (i = 0; mul_buf[i] != NULL; i++) {
            check_commands(test, env, mul_buf[i], bufsize);
        }
    }
}
