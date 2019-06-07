# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:33:24 by arbib             #+#    #+#              #
#    Updated: 2017/11/07 19:33:30 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

HEADER = includes/

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c  srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

SRCO = ft_putchar.o ft_putstr.o  ft_strcmp.o ft_strlen.o ft_swap.o

CC = gcc
AR = ar
LDFLAGS = -Werror -Wextra -Wall -c
all:
	$(CC)  $(LDFLAGS)  $(SRCS) -I $(HEADER)
	$(AR)  rc  $(NAME)  $(SRCO)
clean:
	/bin/rm -f $(SRCO)

fclean: clean
	 /bin/rm -f $(NAME)
re      : fclean all


