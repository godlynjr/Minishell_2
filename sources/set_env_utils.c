/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** set_env_utils
*/

#include "../include/mysh.h"

void line_adder(locker *test, char **cmd)
{
    if (cmd[2]) {
        if (test->apk != 1) {
            add_newline_1(test, cmd[1], cmd[2]);
            test->line++;
        }
    } else if (!cmd[2] && test->apk != 1) {
        add_newline_2(test, cmd[1]);
        test->line++;
    }
}

void search_in_env_1(locker *test, char **cmd)
{
    int i = 0, counter = pos_env(test, cmd);

    for (i = 0; test->envi[i] != NULL; i++) {
        if (my_strncmp(test->envi[i], cmd[1], my_strlen(cmd[1])) == 0) {
            test->apk = 1;
            strtok(test->envi[counter], "=");
            my_strcat(test->envi[counter], "=");
            my_strcat(test->envi[counter], cmd[2]);
            my_strcat(test->envi[counter], "\0");
        }
    }
}

void search_in_env_2(locker *test, char **cmd)
{
    int i = 0, counter = pos_env(test, cmd);

    for (i = 0; test->envi[i] != NULL; i++) {
        if (my_strncmp(test->envi[i], cmd[1], my_strlen(cmd[1])) == 0) {
            test->apk = 1;
            strtok(test->envi[counter], "=");
            my_strcat(test->envi[counter], "=");
            my_strcat(test->envi[counter], "\0");
        }
    }
}
