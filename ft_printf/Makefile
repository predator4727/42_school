NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -cq
C_FILES = ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_point.c ft_print_string.c ft_print_unsigned_int.c
O_FILES = ft_printf.o ft_print_char.o ft_print_hex.o ft_print_int.o ft_print_point.o ft_print_string.o ft_print_unsigned_int.o


$(NAME) : $(O_FILES)
	$(AR) libftprintf.a $(O_FILES)

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $<

clean: 
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re
