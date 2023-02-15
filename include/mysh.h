/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** my.h
*/

#ifndef MYSH_H
    #define MYSH_H
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

struct shortcut {
    int checker;
    int error;
    char **envi;
    int cd;
    int line;
    int apk;
    int column;
    int nb_column;
    int no_direct;
    char *sec_buff;
    int *fd, *fd_file, *fd_file2;
    int *holder;
    int not_found;
};
typedef struct shortcut locker;

int mysh(char *buff, size_t bufsize, char **env, locker *test);
void prompt(void);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int c);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
void get_line(char *buff, size_t bufsize, locker *test);
int parse_line(char **env, locker *test);
char *get_path(locker *test, char *str, int c);
char *delete_path(locker *test, const char *s);
char *my_strcpy(char *dest, char const *src);
char *browse_buff(char *buff);
char **str_to_tab(char *buff);
void free_tab(char **tab);
int execute_builtins(char *buff, char **env, locker *test);
char **str_to_array(locker *test, char *path);
int p_count_words(char *str);
int browse_path(char *buff, char **cmd, char **env, locker *test);
void forker(char *path, char **argv, char **env);
int my_cd(locker *test, char **env, char *buff);
char *cd_path(locker *test);
int display_env(locker *test);
char *rm_space(char *str);
char *rm_tab(char *str);
int check_test(char **cmd, locker *test);
void fill(locker *test, char **env);
void set_env(locker *test, char **cmd);
char **dealer_env(locker *test, char **env, char **cmd);
char **new_env(char **env);
int nb_lines_env(char **env);
int is_alpha_num(char *string);
void add_newline_1(locker *test, char *str1, char *str2);
void add_newline_2(locker *test, char *str1);
void unset_env(locker *test, char **cmd);
void search_in_env_2(locker *test, char **cmd);
void search_in_env_1(locker *test, char **cmd);
void line_adder(locker *test, char **cmd);
int pos_env(locker *test, char **cmd);
char *delete_oldpwd(locker *test);
void set_oldpwd(locker *test, char **keeper, int ch, int cd);
void reset_pwd(locker *test, int i);
char **my_realloc(char **tab);
int cd_choice(locker *test, char **keeper);
char *delete_pwd(char **env);
int nb_lines(char **tab);
char *my_strdup(char *str);
char **my_arr_cpy(char **tab);
int how_many_word(char *string, char c);
char **str_array(char *buff, char c);
void check_column(locker *test, char *buff);
void nb_column(locker *test, char *buff);
void shell(char *buff, size_t bufsize, char **env, locker *test);
void separator(locker *test, char *buff, char **env);
int my_pipe(locker *test, char **cmd);
void check_commands(locker *test, char **env, char *buff, size_t bufsize);
int binary_type(locker *test, char **cmd, char **env);
int my_redirect_out(locker *test, char **cmd, char **env);
int my_redirect_in(locker *test, char **cmd, char **env);
char *is_redirect_file(char **cmd, char *str);
char **cleaner(char **keeper);
int invalid_redirect(char **cmd);
int invalid_pipe(char **cmd);
