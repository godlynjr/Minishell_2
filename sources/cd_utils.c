/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** cd_utils
*/

#include "../include/mysh.h"

int cd_choice(locker *test, char **keeper)
{
    if (my_strcmp(keeper[1], "-") == 0) {
        if (chdir(delete_oldpwd(test)) != 0 || test->no_direct == 1) {
            write(2, ": No such file or directory.\n", 29);
            return 0;
        }
    } else if (access(keeper[1], F_OK) == -1 &&
    my_strcmp(keeper[1], "-") != 0) {
        write(2, "cd: No such file or directory.\n", 31);
        return 0;
    } else {
        write(2, keeper[1], my_strlen(keeper[1]));
        write(2, ": Not a directory.\n", 19);
        return 0;
    }
    return 1;
}

char **my_realloc(char **tab)
{
    int i = 0;
    char **keeper = NULL;

    for (i = 0; tab[i]; i++);
    keeper = malloc(10000);
    for (i = 0; tab[i]; i++)
        keeper[i] = tab[i];
    for (int j = 0; j <= 1; j++)
        keeper[i + 1] = NULL;
    return keeper;
}

void reset_pwd(locker *test, int i)
{
    char *keeper = malloc(1000);

    if (!getcwd(keeper, 1024))
        return;
    if (test->envi[i]);
    else
        test->envi = my_realloc(test->envi);
    test->envi[i] = malloc(sizeof(char) * (my_strlen(keeper) + 5));
    test->envi[i] = my_strcpy(test->envi[i], "PWD=");
    test->envi[i] = my_strcat(test->envi[i], keeper);
    free(keeper);
}

void set_oldpwd(locker *test, char **keeper, int ch, int cd)
{
    int i = 0, j = 0;

    if (ch == 0 || cd == 1) {
        for (; test->envi[i] && my_strncmp(test->envi[i], "PWD", 3); i++);
        for (; test->envi[j] && my_strncmp(test->envi[j], "OLDPWD", 6); j++);
        if (!test->envi[i]) {
            reset_pwd(test, i);
            return;
        }
        if (test->envi[j]);
        else
            test->envi = my_realloc(test->envi);
        test->envi[j] = malloc(sizeof(char) * (my_strlen(test->envi[i]) + 4));
        test->envi[j] = my_strcpy(test->envi[j], "OLD");
        test->envi[j] = my_strcat(test->envi[j], test->envi[i]);
        test->line++;
        reset_pwd(test, i);
    }
}
