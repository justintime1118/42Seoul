# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 10:37:14 by jiyoo             #+#    #+#              #
#    Updated: 2021/10/05 17:16:29 by jiyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = \
2_sort.c \
3_sort_a.c \
3_sort_b.c \
atoi.c \
error_check.c \
inits.c	\
input_check.c \
push_swap.c \
quick_sort.c \
r_rotate.c \
rotate.c \
split.c \
stack_sort_utils.c \
stack_sort_utils_1.c \
stack_sort.c \
swap_and_push.c \
utils.c

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re