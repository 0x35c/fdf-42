# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/12/03 14:45:48 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c drawing.c parsing.c info.c utils.c\
	  gnl/get_next_line.c gnl/get_next_line_utils.c

CC = clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

all: ${NAME}

MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${NAME}: ${OBJ}
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) ${OBJ} -o ${NAME} $(MLX) $(LIBS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ${NAME} 

re: all clean

.PHONY: all clean fclean re
