# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 10:47:11 by aderugo           #+#    #+#              #
#    Updated: 2023/01/22 12:55:09 by aderugo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERPOSE
.SILENT:
endif

NAME = philo

CC = gcc

C_FILES = philo.c start.c utils.c philo_life.c philo_init.c

O_FILES = $(C_FILES:.c=.o)
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf
CC = gcc

$(NAME): $(O_FILES) philo.h
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) -pthread

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME) $(O_FILES)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re