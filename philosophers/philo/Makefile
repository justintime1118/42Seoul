# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 18:59:51 by jiyoo             #+#    #+#              #
#    Updated: 2022/03/11 11:30:52 by jiyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRCS = \
init.c \
main.c \
simulation.c \
utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUSES:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
	HEADER = philo_bonus.h
else
	OBJ_FILES = $(OBJS)
	HEADER = philo.h
endif

all: $(NAME)

bonus:
	make WITH_BONUS=1

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re