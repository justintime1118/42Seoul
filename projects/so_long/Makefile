# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 18:59:51 by jiyoo             #+#    #+#              #
#    Updated: 2022/01/27 17:10:30 by jiyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = so_long

SRCS = \
get_next_line.c \
interaction.c \
itoa.c \
map_check.c \
map_draw_utils.c \
map_draw.c \
map_save.c \
move_utils.c \
move.c \
so_long.c \
utils.c

BONUSES = \
./bonus/get_next_line_bonus.c \
./bonus/interaction_bonus.c \
./bonus/itoa_bonus.c \
./bonus/map_check_bonus.c \
./bonus/map_draw_utils_bonus.c \
./bonus/map_draw_bonus.c \
./bonus/map_save_bonus.c \
./bonus/move_utils_bonus.c \
./bonus/move_bonus.c \
./bonus/so_long_bonus.c \
./bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUSES:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
	HEADER = so_long_bonus.h
else
	OBJ_FILES = $(OBJS)
	HEADER = so_long.h
endif

all: $(NAME)

bonus:
	make WITH_BONUS=1

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework Appkit -I $(HEADER) $(OBJ_FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re