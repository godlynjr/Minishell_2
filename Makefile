##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make
##

ECHO	=	echo

COLOR	=	31
LIGHT	=	\e[0m
BOLD	=	\e[1m
BLACK	=	\e[30m
RED	=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
PURPLE	=	\e[35m
CYAN	=	\e[36m
WHITE	=	\e[37m
DEFAULT	=	\e[0;37m

INFO	=	$(BOLD)$(GREEN)[INFO]\t$(WHITE)
CLEANER	=	$(BOLD)$(PURPLE)[CLEANER]\t$(WHITE)
WARNING	=	$(BOLD)$(YELLOW)[WARNING]\t$(WHITE)
ERROR	=	$(BOLD)$(RED)[ERROR]\t$(WHITE)

SRC_DIR	=	./sources/
INC_DIR	=	./include/

NAME	=	mysh

CC	=	gcc

RM	=	rm -f

SRC	=	./sources/main.c	\
		./sources/parser.c	\
		./sources/mysh.c	\
		./sources/fork.c	\
		./sources/browser.c	\
		./sources/builtins.c	\
		./sources/cmd_utils.c	\
		./sources/execute_env.c	\
		./sources/env_utils.c	\
		./sources/utils/str_to_wordtab.c	\
		./sources/utils/path_to_tab.c	\
		./sources/path.c	\
		./sources/execute_cd.c	\
		./sources/set_env.c	\
		./sources/set_env_utils.c	\
		./sources/unset_env.c	\
		./sources/cd_utils.c	\
		./sources/separator.c	\
		./sources/execute_pipe.c	\
		./sources/utils/my_putstr.c	\
		./sources/utils/my_putchar.c	\
		./sources/utils/my_strlen.c	\
		./sources/utils/my_strcat.c	\
		./sources/utils/my_strcpy.c	\
		./sources/utils/my_strcmp.c	\
		./sources/utils/my_strncmp.c	\
		./sources/utils/cleaner.c	\
		./sources/utils/my_strdup.c	\
		./sources/utils/str_to_tab.c	\
		./sources/execute_binary.c	\
		./sources/exec_redirect_out.c	\
		./sources/redirect_utils.c	\
		./sources/invalid.c	\
		./sources/exec_redirect_in.c	\

TEST	=	./sources/utils/my_putstr.c	\
		./sources/utils/my_strlen.c	\
		./sources/utils/my_putchar.c	\
		./tests/test.c	\

OBJ	= $(SRC:.c=.o)

OBJTEST	=	$(TEST:.c=.o)

NAMETEST	=	unitest

TESTIN	=	-o $(NAMETEST) $(TEST) --coverage -lcriterion

all:	setup $(NAME)

%.o:	%.c
	gcc -c $<  -o $@ -g3

$(NAME):	$(OBJ)
	@$(ECHO) "$(BOLD) $(BLUE)"
	$(CC) -o $(NAME) $(OBJ)
	@$(ECHO) "\n"
	@$(ECHO) "$(INFO)Build complete !$(DEFAULT)"
	@$(ECHO) "\n"
	make clean

clean:
	@$(ECHO) "\n"
	@$(ECHO) "$(BOLD)$(RED)[Delete mode]"
	$(RM) $(OBJ)
	$(RM) *.gcda *.gcno
	@$(ECHO) "$(RED)"
	@$(ECHO) "$(CLEANER)Files removed !$(DEFAULT)"

fclean:	clean
	@$(ECHO) "$(YELLOW)"
	$(RM) $(NAME)

re: fclean all

tests_run:	$(TEST)
	$(CC) $(TESTIN) -lncurses
	./unitest

setup:
	@$(ECHO) "\n$(BOLD)$(WHITE)Project setup : $(CYAN)$(NAME)$(DEFAULT)\n"
	@mkdir -p $(SRC_DIR) && $(ECHO) "$(INFO)$(SRC_DIR)\t\t$(GREEN)[OK]\
	$(DEFAULT)" || $(ECHO) "$(ERROR)$(SRC_DIR)\t\t\t$(RED)[x]$(DEFAULT)"
	@mkdir -p $(INC_DIR) && $(ECHO) "$(INFO)$(INC_DIR)\t\t$(GREEN)[OK]\
	$(DEFAULT)" || $(ECHO) "$(ERROR)$(INC_DIR)\t\t$(RED)[x]$(DEFAULT)"
	@$(ECHO) "\n"
