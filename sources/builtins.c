/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** built=ins
*/

#include "../include/mysh.h"

int builtin_holder(char **cmd, char **env, char *buff, locker *test)
{
    int a = 0;

    if (my_strcmp(cmd[0], "env") == 0 ||
        my_strcmp(cmd[0], "setenv") == 0 ||
        my_strcmp(cmd[0], "unsetenv") == 0) {
        dealer_env(test, cmd, env);
    } else
        browse_path(buff, cmd, env, test);
    return a;
}

int execute_builtins(char *buff, char **env, locker *test)
{
    pid_t pid = 0;
    test->checker = 0;
    int a = 0, i = 0;
    char **cmd = str_to_tab(buff);

    test->sec_buff = buff;
    for (i = 0; cmd[i] != NULL; i++);
    if (i != 0) {
        if (binary_type(test, cmd, env) == 1)
            return 0;
        if (my_strcmp(cmd[0], "cd") == 0)
            my_cd(test, env, buff);
        else {
            test->error = builtin_holder(cmd, env, buff, test);
            a = test->error;
        }
    }
    return 0;
}
