NAME = minishell
CC = cc
READLINE = -lreadline
FLAGS = -Wall -Wextra -Werror

SRC = orbiay/functions_libft.c orbiay/minishell.c orbiay/redirection_errors.c\
	aabeid/utils/redirections.c orbiay/ft_split.c orbiay/pipes_errors.c\
	aabeid/builtins/unset.c aabeid/executer.c orbiay/file_create_and_add.c	\
	aabeid/builtins/cd.c aabeid/builtins/echo.c	orbiay/create2.c orbiay/if_expand.c \
	aabeid/builtins/env.c aabeid/builtins/exit.c orbiay/type2.c orbiay/join_space_pipe.c\
	aabeid/builtins/export.c aabeid/builtins/pwd.c orbiay/file.c orbiay/main_sec.c	\
	aabeid/utils/ft_strtrim.c aabeid/utils/pipes.c	\
	aabeid/utils/ft_lstadd_back.c orbiay/strncmp.c	\
	aabeid/get_var_len.c aabeid/main.c orbiay/type.c \
	aabeid/utils/ft_strchr.c aabeid/utils/ft_strcmp.c \
	aabeid/errors_handler.c \
	aabeid/expander.c aabeid/builtins/export_gear.c\
	aabeid/utils/ft_lstnew.c aabeid/utils/gear.c 		\
	orbiay/add_apaces.c orbiay/errors.c aabeid/path_getter_finder.c	\
	aabeid/utils/ft_lstsize.c aabeid/utils/heredoc.c 	\
	aabeid/utils/ft_lstadd_front.c aabeid/utils/ft_lstlast.c orbiay/signal.c	\
	aabeid/utils/ft_strlen.c aabeid/utils/ft_strncmp.c	aabeid/utils/ft_itoa.c	\
	aabeid/utils/ft_lstmap.c aabeid/utils/ft_lstclear.c aabeid/utils/ft_atoi.c	\
	aabeid/utils/ft_strdup.c aabeid/utils/ft_strjoin.c aabeid/utils/ft_isalpha.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@stty -echoctl
	$(CC) $(READLINE) $(FLAGS) $(OBJ) -lreadline -L ~/Documents/brew/opt/readline/lib -I ~/Documents/brew/opt/readline/include -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
