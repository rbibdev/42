# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <arbib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 21:29:16 by arbib             #+#    #+#              #
#    Updated: 2017/11/22 00:55:00 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =   ft_atoi.c \
        ft_bzero.c \
        ft_isascii.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_itoa.c\
        ft_memalloc.c \
        ft_memccpy.c \
        ft_memchr.c\
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memdel.c \
        ft_memmove.c \
        ft_memset.c \
        ft_putchar.c \
        ft_putchar_fd.c \
        ft_putendl_fd.c\
        ft_putendl.c \
        ft_putnbr_fd.c \
        ft_putnbr.c \
        ft_putstr_fd.c \
        ft_putstr.c \
        ft_strcat.c\
        ft_strchr.c\
        ft_strclr.c \
        ft_strcpy.c \
        ft_strdel.c \
        ft_strdup.c \
        ft_strequ.c \
        ft_striter.c \
        ft_strjoin.c \
        ft_strlen.c \
        ft_striteri.c \
        ft_strmap.c \
        ft_strmapi.c \
        ft_strncat.c \
        ft_strncpy.c \
        ft_strnequ.c \
        ft_strnew.c \
        ft_strsplit.c \
        ft_strstr.c \
        ft_strsub.c \
        ft_strtrim.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strcmp.c \
        ft_strncmp.c \
        ft_strrchr.c \
        ft_strnstr.c \
        ft_strlcat.c \
        ft_lstnew.c \
        ft_lstdelone.c \
        ft_lstdel.c \
        ft_lstadd.c \
        ft_lstiter.c \
        ft_lstmap.c \
        ft_strrev.c \
        ft_sqrt.c \
        ft_count_if.c \
        ft_sort_tab.c \
        ft_pwr.c \

OBJ = $(patsubst %.c,%.o,$(SRC))
HEADER = libft.h
all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -c  $(LDFLAGS)  $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all