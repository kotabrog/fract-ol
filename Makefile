# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 10:09:42 by ksuzuki           #+#    #+#              #
#    Updated: 2021/07/10 17:47:40 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	= ./srcs/
SRCNAME	=	main.c\
			error.c\
			minilibx_control1.c\
			fractol_square.c\
			color.c\
			trgb_to_int.c\
			trgb_to_one.c\
			mini_libft1.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

INCLUDE	= -I/usr/include -I./minilibx-linux
NAME	= fractol
LDFLAGS	= ./minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.c.o	:
	if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
	if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

sani	:	$(OBJS)
	if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LDFLAGS) -o $(NAME)

bonus	: $(OBJS)
	if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY: all re fclean clean bonus
