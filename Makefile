# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/12/09 13:28:55 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = mandatory/main.c mandatory/drawing.c mandatory/parsing.c\
	  mandatory/info.c mandatory/utils.c\
	  libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c\

SRCB = bonus/main_bonus.c bonus/drawing_bonus.c bonus/parsing_bonus.c\
	  bonus/info_bonus.c bonus/utils_bonus.c bonus/events_bonus.c\
	  libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c\

CC = @clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibs/libft -lft -Llibs/libft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

ifdef bonus
	SRC = ${BONUS_SRC}
endif

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: ${NAME}

bonus: ${NAME}_B

MLX = -Llibs/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${NAME}: ${OBJ}
	@make -C libs/libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'
	@make -C libs/minilibx-linux > /dev/null
	@printf '\x1b[38;2;50;205;50mMiniLibX compiled 🤓\n\x1b[0m'
	$(CC) ${OBJ} -o ${NAME} $(MLX) $(LIBS)
	@printf '\x1b[38;2;50;205;50mWireframe compiled 🤓\n\x1b[0m'

${NAME}_B: ${OBJB}
	@make -C libs/libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'
	@make -C libs/minilibx-linux > /dev/null
	@printf '\x1b[38;2;50;205;50mMiniLibX compiled 🤓\n\x1b[0m'
	$(CC) ${OBJB} -o ${NAME}_b $(MLX) $(LIBS)
	@printf '\x1b[38;2;50;205;50mBonus Wireframe compiled 🤓\n\x1b[0m'

clean:
	@rm -f $(OBJ)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mObjects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean: clean
	@rm -f ${NAME} 
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBinary removed\x1b[0m\e[5m 🚨\n\e[0m'

clean_b:
	@rm -f $(OBJB)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mBonus objects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean_b: clean_b
	@rm -f ${NAME}_b
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBonus binary removed\x1b[0m\e[5m 🚨\n\e[0m'

re: fclean all

re_b: fclean_b bonus

.PHONY: all clean fclean re
