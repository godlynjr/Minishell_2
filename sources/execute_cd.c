/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** cd
*/

#include "../include/mysh.h"

char *delete_oldpwd(locker *test)
{
    int i = 0, j = 0;
    char *oldpwd;
    char *keeper = malloc(sizeof(char) * 1000);
    oldpwd = get_path(test, "OLDPWD=", 7);

    if (oldpwd == NULL)
        return NULL;
    for (i = 0; oldpwd[i] != '='; i++);
    i++;
    for (j = 0; oldpwd[i] != '\0'; i++, j++)
        keeper[j] = oldpwd[i];
    keeper[j] = '\0';
    return (keeper);
}

char *delete_home(locker *test, char *s)
{
    int i = 0, j = 0;
    char *pwd;
    char *keeper = malloc(sizeof(char) * 1000);
    pwd = get_path(test, s, 5);

    if (pwd == NULL) return NULL;
    for (i = 0; pwd[i] != '='; i++);
    i++;
    for (j = 0; pwd[i] != '\0'; i++, j++)
        keeper[j] = pwd[i];
    keeper[j] = '\0';
    return (keeper);
}

char *cd_path(locker *test)
{
    int i = 0, j = 0;
    char *home = delete_home(test, "HOME=");;
    char *keeper = NULL;

    if (home == NULL) return NULL;
    keeper = malloc(sizeof(char) * (my_strlen(home) * 100));
    while (home[j] != '\0') {
        keeper[i] = home[j];
        i++;
        j++;
    }
    keeper[i] = '\0';
    if (keeper == NULL)
        return 0;
    return (keeper);
}

int my_cd(locker *test, char **env, char *buff)
{
    int ch, cd = 0;
    char **keeper = str_to_tab(buff);
    char *to_home = cd_path(test);

    if (keeper == NULL)
        return (0);
    if (keeper[2])
        write(2, "cd: Too many arguments.\n", 25);
    if (!keeper[1]) {
        chdir(to_home);
        cd = 1;
    } else if ((ch = chdir(keeper[1])) == -1 && opendir(keeper[1]) == NULL)
        cd = cd_choice(test, keeper);
    set_oldpwd(test, keeper, ch, cd);
    return (0);
}
