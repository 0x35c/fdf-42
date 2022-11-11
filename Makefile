# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/11/10 16:32:39 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = parsing.c test_mlx.c\
	  gnl/get_next_line.c gnl/get_next_line_utils.c

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

LIBS = -Llibft -lft -Llibft/printf -lftprintf
OBJ = $(SRC:.c=.o)

all: ${NAME}

MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

makemlx:
	make re -C ./minilibx-linux

makelibft:
	make re -C ./libft

${NAME}: makemlx makelibft ${OBJ}
	$(CC) -o ${NAME} $(OBJ) $(MLX) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ${NAME} 

re: all clean

.PHONY: all clean fclean re
