# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/11/09 14:03:50 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = parsing.c main.c\
	  gnl/get_next_line.c gnl/get_next_line_utils.c

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

LIBS = -Llibft -lft -Llibft/printf -lftprintf
OBJ = $(SRC:.c=.o)

all: ${NAME}

makemlx:
	make re -C ./MLX42

makelibft:
	make re -C ./libft

${NAME}: makemlx makelibft ${OBJ}
	$(CC) -o ${NAME} $(OBJ) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ${NAME} 

re: all clean

.PHONY: all clean fclean re
