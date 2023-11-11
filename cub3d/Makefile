# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 14:46:09 by aderugo           #+#    #+#              #
#    Updated: 2023/04/04 22:05:59 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror

C_FILES = 		cub3d.c									\
				basic_checks.c							\
				map_interaction_utils.c					\
				map_interaction.c						\
				texture_fc_interaction_utils.c			\
				texture_fc_interaction.c				\
				game_coordinates_check.c				\
				game_data_init.c						\
				game_data_update.c						\
				game_drawing.c							\
				key_hook.c								\
				rendering.c								\
				ray_utils.c								\

O_FILES = $(C_FILES:.c=.o)
LIB = libft/libft.a
LIBFT = cd libft && make bonus
MLX = ./mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(O_FILES)
		$(LIBFT)
		make -C ./mlx
		$(CC) $(CFLAGS) -o ${NAME} $(O_FILES) $(LIB) $(MLX) ${MLX_FLAGS}

%.o : %.c
	$(CC) -c $(CFLAGS) -Imlx $<

clean:
	$(RM) $(O_FILES)
	make -C ./libft clean
	cd mlx && make clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(O_FILES)
	make -C ./libft fclean
	cd mlx && make clean

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus mlx libft
