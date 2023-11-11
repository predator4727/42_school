NAME = array
CC = c++
RM = rm -f
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX_FILES = main.cpp
OXX_FILES = $(CXX_FILES:.cpp=.o)

$(NAME) : $(OXX_FILES)
	$(CC) $(CXXFLAGS) $(CXX_FILES) -o $(NAME)

%.o : %.c
	$(CC) -c -t $(CXXFLAGS) $<

clean:
	$(RM) $(OXX_FILES)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re