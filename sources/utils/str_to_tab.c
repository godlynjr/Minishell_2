/*
** EPITECH PROJECT, 2022
** B-PSU-210-COT-2-1-minishell2-godlyn.kikissagbe
** File description:
** str_to_tab
*/

#include "../../include/mysh.h"
#include "../../include/mysh_2.h"

char *clean_buff(char *buff)
{
    char *keeper = malloc(sizeof(char) * my_strlen(buff));
    int i = 0, j = 0;

    for (i = 0; buff[i] == ' '; i++);
    for (j = 0; buff[i] != '\0'; i++, j++) {
        if (buff[i] == ' ' && buff[i + 1] == ' ')
            i++;
        else
            keeper[j] = buff[i];
    }
    keeper[j] = '\0';
    return keeper;
}

int how_many_word(char *string, char c)
{
    int word = 0;
    int i = 0;

    for (i = 0; string[i] == ' ' || string[i] == '\t'; i++);
    for (; string[i] != '\0'; i++) {
        if ((string[i] == ' ' || string[i] == '\t' || string[i] == c) &&
            string[i + 1] != ' ' && string[i + 1] != '\t' &&
            string[i + 1] != '\0' && string[i + 1] != c) {
            word++;
        }
    }
    return (word + 1);
}

char **str_array(char *buff, char c)
{
    char **keeper = malloc(sizeof(char *) * (how_many_word(buff, c) + 1));
    int i = 0, o = 0, x = 0;

    keeper[o] = malloc(sizeof(char) * (my_strlen(buff) + 1));
    for (i = 0; buff[i] == ' ' || buff[i] == '\t'; i++);
    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == c && buff[i + 1] != '\0') {
            keeper[o][x] = '\0';
            o++;
            x = 0;
            keeper[o] = malloc(sizeof(char) * (my_strlen(buff) + 1));
        } else if (buff[i] != c && buff[i] != '\0') {
            keeper[o][x] = buff[i];
            x++;
        }
    }
    keeper[o + 1] = NULL;
    return keeper;
}
