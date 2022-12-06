# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/12/06 10:47:17 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = mandatory/main.c mandatory/drawing.c mandatory/parsing.c\
	  mandatory/info.c mandatory/utils.c\
	  gnl/get_next_line.c gnl/get_next_line_utils.c\

CC = @clang

CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

all: ${NAME}

MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${NAME}: ${OBJ}
	@make -C ./libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled !\n\x1b[0m'
	@make -C ./minilibx-linux > /dev/null
	@printf '\x1b[38;2;50;205;50mMiniLibX compiled !\n\x1b[0m'
	$(CC) ${OBJ} -o ${NAME} $(MLX) $(LIBS)

clean:
	@rm -f $(OBJ)
	@printf '\x1b[38;2;255;140;0mObjects removed !\n\x1b[0m'

fclean: clean
	@rm -f ${NAME} 
	@printf '\x1b[38;2;200;0;20mBinary removed !\n\x1b[0m'

re: all fclean

.PHONY: all clean fclean re
