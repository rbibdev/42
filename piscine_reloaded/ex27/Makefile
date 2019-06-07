# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:37:50 by arbib             #+#    #+#              #
#    Updated: 2017/11/07 19:37:54 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

RM = rm -f

NAME = ft_display_file

SRCS = ft_display_file.c   \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	  $(CC) -o $(NAME) $(OBJS)

clean:
	  $(RM) $(OBJS)

fclean: clean
	  $(RM) $(NAME)

re:  fclean all

