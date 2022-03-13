# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 10:37:14 by jiyoo             #+#    #+#              #
#    Updated: 2021/08/13 17:35:28 by jiyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = \
ft_c_utils.c \
ft_form_id_utils_2.c \
ft_form_id_utils.c \
ft_i_negative_utils.c \
ft_i_positive_utils.c \
ft_i_utils.c \
ft_i_zero_utils.c \
ft_p_utils.c \
ft_parse_utils.c \
ft_printf_utils_2.c \
ft_printf_utils_put_2.c \
ft_printf_utils_put.c \
ft_printf_utils.c \
ft_printf.c \
ft_s_utils.c \
ft_u_utils.c \
ft_x_lower_utils.c \
ft_x_upper_utils.c

BONUSES = \
ft_c_utils_bonus.c \
ft_form_id_utils_2_bonus.c \
ft_form_id_utils_bonus.c \
ft_i_negative_utils_bonus.c \
ft_i_positive_utils_bonus.c \
ft_i_utils_bonus.c \
ft_i_zero_utils_bonus.c\
ft_p_utils_bonus.c \
ft_parse_utils_bonus.c \
ft_printf_utils_2_bonus.c \
ft_printf_utils_put_2_bonus.c \
ft_printf_utils_put_bonus.c \
ft_printf_utils_bonus.c \
ft_printf_bonus.c \
ft_s_utils_bonus.c \
ft_u_utils_bonus.c \
ft_x_lower_utils_bonus.c \
ft_x_upper_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUSES:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar crs $@ $(OBJ_FILES)

bonus:
	make WITH_BONUS=1

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re