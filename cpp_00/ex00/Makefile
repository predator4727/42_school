NAME = megaphone
CC = c++
RM = rm -f
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
C_FILES = megaphone.cpp
O_FILES = $(C_FILES:.cpp=.o)

$(NAME) : $(O_FILES)
	$(CC) $(CFLAGS) $(C_FILES) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re