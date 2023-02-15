/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** path
*/

#include "../include/mysh.h"

int browse_path(char *buff, char **cmd, char **env, locker *test)
{
    int i = 0, j = 0, k = 0;
    char *holder = delete_path(test, "PATH="), *keeper = NULL;
    char **path = str_to_array(test, holder);

    if (path == NULL) return check_test(cmd, test);
    for (i = 0; path[i] != NULL; i++) {
        j = my_strlen(path[i]) + my_strlen(buff);
        keeper = malloc(sizeof(char) * (j * 100));
        keeper = my_strcpy(keeper, path[i]);
        keeper[my_strlen(path[i]) + 1] = '\0';
        keeper = my_strcat(keeper, "/");
        keeper = my_strcat(keeper, cmd[0]);
        if (access(keeper, X_OK) == 0) {
            test->checker = 1;
            break;
        }
    }
    forker(keeper, cmd, env);
    return check_test(cmd, test);
}
