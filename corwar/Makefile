# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <arbib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 22:40:12 by arbib             #+#    #+#              #
#    Updated: 2019/05/04 04:59:33 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS =	src/main.c src/read_file.c src/parse_file.c src/token_file.c src/op.c src/convert_file.c src/write_file.c src/free_file.c src/addition_file.c  src/value_file.c

SRCS += libft/ft_atoi.c \
        libft/ft_isdigit.c \
        libft/ft_isspace.c \
        libft/ft_lstadd.c \
        libft/ft_lstnew.c \
        libft/ft_memalloc.c \
        libft/ft_memcpy.c \
        libft/ft_memdel.c \
        libft/ft_putchar_fd.c \
        libft/ft_putendl_fd.c\
        libft/ft_putnbr_fd.c \
        libft/ft_putstr_fd.c \
        libft/ft_strchr.c\
        libft/ft_strcmp.c \
        libft/ft_strdup.c \
        libft/ft_strlen.c \
        libft/ft_strncpy.c \
        libft/ft_strnew.c \
        libft/ft_strrchr.c \
        libft/ft_strsub.c \
        libft/ft_strtrim.c \
        libft/get_next_line.c \
        libft/ft_bzero.c \
        libft/ft_strjoin.c \
        libft/ft_putnbr.c \
        libft/ft_putchar.c \
        libft/ft_putstr.c \

HEADER = include/asm.h include/op.h

HEADER += libft/includes/libft.h libft/includes/get_next_line.h

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): | obj

obj:

obj/%.o: %.c libft/%.c $(HEADER)
	gcc $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS) $(HEADER)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)
	
clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
