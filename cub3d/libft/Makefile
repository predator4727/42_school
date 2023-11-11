NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -cq
C_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_point.c ft_print_string.c ft_print_unsigned_int.c  
O_FILES = $(C_FILES:.c=.o)
C_FILES_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
O_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

$(NAME) : $(O_FILES) libft.h
	$(AR) libft.a $(O_FILES)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean: 
	$(RM) $(O_FILES) $(O_FILES_BONUS)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

bonus: $(O_FILES) $(O_FILES_BONUS)
	$(AR) libft.a $(O_FILES) $(O_FILES_BONUS)

.PHONY:	all clean fclean re bonus		
