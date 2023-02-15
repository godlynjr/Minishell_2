/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** cmd_utils
*/

#include "../include/mysh.h"
#include "../include/mysh_2.h"

int check_test(char **cmd, locker *test)
{
    if (test->checker == 0 && access(cmd[0], X_OK) != 0) {
        write(2, cmd[0], my_strlen(cmd[0]));
        write(2, ": Command not found.\n", 21);
        return 0;
    }
}

void check_column(locker *test, char *buff)
{
    int i = 0;

    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ';')
            test->column = 1;
    }
}

void nb_column(locker *test, char *buff)
{
    int i = 0;

    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ';')
            test->nb_column++;
    }
}

char *browse_buff(char *buff)
{
    int i = 0;

    if (buff[i] == ' ')
        i++;
    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            strtok(buff, "\n");
        i++;
    }
    return buff;
}
