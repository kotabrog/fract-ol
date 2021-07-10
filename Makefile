# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 10:09:42 by ksuzuki           #+#    #+#              #
#    Updated: 2021/07/10 13:52:14 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	= ./srcs/
SRCNAME	=	main.c\
			minilibx_control1.c\
			color.c\
			mini_libft1.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

INCLUDE	= -I/usr/include
NAME	= fractol
LDFLAGS	= libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

sani	:	$(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LDFLAGS) -o $(NAME)

bonus	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY: all re fclean clean bonus
