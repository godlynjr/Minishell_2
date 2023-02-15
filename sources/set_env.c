/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** set_env
*/

#include "../include/mysh.h"

int pos_env(locker *test, char **cmd)
{
    int i = 0;

    for (i = 0; test->envi[i] != NULL; i++) {
        if (my_strncmp(test->envi[i], cmd[1], my_strlen(cmd[1])) == 0)
            return i;
    }
    return -1;
}

void set_env2(locker *test, char **cmd)
{
    if (cmd[1] && cmd[2]){
        if (is_alpha_num(cmd[1]) == 2) {
            write(2, "setenv", 7);
            write(2, ": Variable name must begin with a letter.\n", 43);
        } else if (is_alpha_num(cmd[1]) == 1 || is_alpha_num(cmd[2]) == 1) {
            write(2, "setenv: Variable ", 18);
            write(2, "name must contain alphanumeric characters.\n", 44);
        } else {
            search_in_env_1(test, cmd);
            line_adder(test, cmd);
        }
    }
}

void set_env(locker *test, char **cmd)
{
    test->apk = 0;
    if (cmd[1] && !cmd[2]) {
        if (is_alpha_num(cmd[1]) == 2) {
            write(2, "setenv", 7);
            write(2, ": Variable name must begin with a letter.\n", 43);
        } else if (is_alpha_num(cmd[1]) == 1) {
            write(2, "setenv: Variable ", 18);
            write(2, "name must contain alphanumeric characters.\n", 44);
        } else {
            search_in_env_2(test, cmd);
            line_adder(test, cmd);
        }
    }
    set_env2(test, cmd);
}
