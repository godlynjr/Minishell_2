/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** parser
*/

#include "../include/mysh.h"

void prompt(void)
{
    size_t keeper_s = 1000;
    char *keeper = malloc(sizeof(char) * keeper_s);
    keeper = getcwd(keeper, keeper_s);
    char *gk = my_strcat(keeper, "] $> ");
    my_putchar('[');
    my_putstr(gk);
    free(keeper);
}

int parse_line(char **env, locker *test)
{
    char *buff;
    size_t bufsize = 200;
    buff = malloc(sizeof(char) * bufsize);
    int a = 0;

    if (buff == NULL) {
        perror("Nothing to display !");
        return (0);
    }
    mysh(buff, bufsize, env, test);
}
