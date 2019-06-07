# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <arbib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 01:55:59 by arbib             #+#    #+#              #
#    Updated: 2017/12/19 01:56:01 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = fillit.c check_fillit.c save_tetri.c solve_tetri.c ft_additionnelles.c

OBJ = $(SRCS:.c=.o)

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(SRCS) -I $(HEADER) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


