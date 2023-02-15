/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** to word tab
*/

#include "../../include/mysh.h"

char **cleaner(char **keeper)
{
    int i = 0, j = 0;
    char **holder = malloc(100000);

    for (i = 0, j = 0; keeper[i] != NULL; i++, j++) {
        holder[j] = rm_space(keeper[i]);
        holder[j] = rm_tab(holder[j]);
    }
    holder[j] = NULL;
    return holder;
}

int count_words2(char *str)
{
    int i = 0, j = 0;

    while (str[j] != '\0') {
        if (str[j] == ' ' && str[j + 1] != ' ')
            i++;
        j++;
    }
    return i;
}

char **str_to_tab(char *buff)
{
    int i = 0, x = 0, o = 0, j = 0, k = 0, word = count_words2(buff);
    char **keeper = malloc(100000);

    for (o = 0; o < my_strlen(buff); o++)
        keeper[o] = malloc(sizeof(char) * (my_strlen(buff) * 4));
    for (x = 0; buff[x] == ' ' || buff[x] == '\t'; x++);
    for (; buff[x] != '\0'; x++)
        if ((buff[x] == ' ' && buff[x + 1] != ' ') ||
            (buff[x] == '\t') && buff[x + 1] != '\t') {
            keeper[k][j] = '\0';
            k++, j = 0;
        } else if (buff[x] != ' ' || buff[x] != '\t' && buff[x + 1] != '\t')
            keeper[k][j] = buff[x], j++;
    if (buff[x - 1] != ' ' && buff[x - 1] != '\t') {
        keeper[k][j] = '\0';
        k++;
    }
    keeper[k] = NULL;
    return cleaner(keeper);
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
