# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <arbib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 21:23:32 by arbib             #+#    #+#              #
#    Updated: 2018/03/06 15:50:41 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_recup.c \
		ft_extra_01.c \
		ft_extra_02.c \
		ft_extra_03.c \
		traitement/ft_conv_int_long_hex_octal.c \
		traitement/ft_conv_char_str_wchar_wstr.c \
		traitement/ft_chw_point_echap_bin_unsign.c \

SRCS +=		libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_isdigit.c \
			libft/ft_itoa.c\
			libft/ft_memalloc.c \
			libft/ft_putchar.c \
			libft/ft_putnbr.c \
			libft/ft_putstr.c \
			libft/ft_strchr.c\
			libft/ft_strlen.c	\
			libft/ft_strsub.c \
			libft/ft_putnbrbase.c \
			libft/ft_tolower.c \
			libft/ft_max.c \

HEADER = include/ft_printf.h

HEADER += libft/libft.h

CFLAGS =  -c -g3 -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): | obj

obj:

obj/%.o: %.c traitement/%.c libft/%.c
	gcc $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)
	
clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
