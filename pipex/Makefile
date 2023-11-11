NAME = pipex
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror
C_FILES = pipex.c utility_1.c utility_2.c utility_3.c pipex_errors.c pipex_free.c
O_FILES = pipex.o utility_1.o utility_2.o utility_3.o pipex_errors.o pipex_free.o

$(NAME) : $(O_FILES)
	$(CC) $(CFLAGS) $(C_FILES) -o pipex

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re