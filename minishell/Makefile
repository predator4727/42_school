NAME = minishell

MAKE = make

CC = gcc


LIBFTDIR = ./libft

LIBFT_A = ./libft/libft.a

prefix		=	/usr/local/Cellar/readline/8.1
# prefix		=	/opt/homebrew/Cellar/readline/8.1.2

exec_prefix	=	${prefix}

libdir		=	${exec_prefix}/lib

includedir	=	${prefix}/include

#-fsanitize=address
CFLAG = -Wall -Werror -Wextra -g3 -I${includedir} 

LDFLAGS 	=	-lreadline -L /usr/local/Cellar/readline/8.1/lib

LDFLAGS 	=	-lreadline -L${libdir}

SRC	=   ./src/execution/builtin_parent.c ./src/execution/builtin_child.c\
		./src/execution/start_execute.c ./src/execution/ft_export.c\
		./src/list/list_operation.c ./src/list/ft_env_list.c\
		./src/list/env_list_to_str.c ./src/parsing/check_quotes.c\
		./src/execution/minishell_call.c ./src/parsing/expansions.c\
		./src/parsing/expansion_utils.c ./src/parsing/basic_pars.c\
		./src/parsing/builtin_parser.c ./src/parsing/start_pars.c\
		./src/parsing/pars_utils.c ./src/redirection/heredog.c\
		./src/helpers/free_1.c ./src/helpers/free_2.c\
		./src/helpers/print_struct.c ./src/parsing/pipes_pars.c\
		./src/redirection/redirect_utils.c ./src/pipes/pipes.c\
		./src/pipes/pipes_utils.c ./src/redirection/redirection.c\
		./src/signals/signals.c ./src/list/rdr_cmd_utils.c\
		./src/helpers/error_msg.c ./src/execution/builtin_utils.c\
		./src/redirection/heredog_utils.c ./src/redirection/prepare_redirect.c\
		minishell.c	

HEADER	= minishell.h

OBJ	= $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

.c.o: $(HEADER)
		$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAG) $(SRC) $(LIBFT_A) -o $(NAME) $(LDFLAGS) && clear

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) $(OBJ) && clear

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME) && clear

re: fclean all

.PHONY: all clean fclean re