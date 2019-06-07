# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbib <arbib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 13:37:10 by arbib             #+#    #+#              #
#    Updated: 2018/10/26 15:22:29 by arbib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

SRCS =  lemin_juice00.c \
        lemin_juice01.c \
        lemin_juice02.c \
        lemin_juice03.c \
        parseur_norm00.c \
        parseur_norm01.c \
        parseur_norm02.c \
        parseur_norm03.c \
        parseur_norm04.c \
        parseur_norm05.c \
        handler_error.c \


SRCS +=	libft/ft_atoi.c \
        libft/ft_bzero.c \
        libft/ft_isascii.c \
        libft/ft_isalpha.c \
        libft/ft_isdigit.c \
        libft/ft_isprint.c \
        libft/ft_itoa.c\
        libft/ft_memalloc.c \
        libft/ft_memccpy.c \
        libft/ft_memchr.c\
        libft/ft_memcmp.c \
        libft/ft_memcpy.c \
        libft/ft_memdel.c \
        libft/ft_memmove.c \
        libft/ft_memset.c \
        libft/ft_putchar.c \
        libft/ft_putchar_fd.c \
        libft/ft_putendl_fd.c\
        libft/ft_putendl.c \
        libft/ft_putnbr_fd.c \
        libft/ft_putnbr.c \
        libft/ft_putstr_fd.c \
        libft/ft_putstr.c \
        libft/ft_strcat.c\
        libft/ft_strchr.c\
        libft/ft_strclr.c \
        libft/ft_strcpy.c \
        libft/ft_strdel.c \
        libft/ft_strdup.c \
        libft/ft_strequ.c \
        libft/ft_striter.c \
        libft/ft_strjoin.c \
        libft/ft_strlen.c \
        libft/ft_striteri.c \
        libft/ft_strmap.c \
        libft/ft_strmapi.c \
        libft/ft_strncat.c \
        libft/ft_strncpy.c \
        libft/ft_strnequ.c \
        libft/ft_strnew.c \
        libft/ft_strsplit.c \
        libft/ft_strstr.c \
        libft/ft_strsub.c \
        libft/ft_strtrim.c \
        libft/ft_toupper.c \
        libft/ft_tolower.c \
        libft/ft_strcmp.c \
        libft/ft_strncmp.c \
        libft/ft_strrchr.c \
        libft/ft_strnstr.c \
        libft/ft_strlcat.c \
        libft/ft_lstnew.c \
        libft/ft_lstdelone.c \
        libft/ft_lstdel.c \
        libft/ft_lstadd.c \
        libft/ft_lstiter.c \
        libft/ft_lstmap.c \
        libft/ft_strrev.c \
        libft/ft_sqrt.c \
        libft/ft_count_if.c \
        libft/ft_sort_tab.c \
        libft/ft_pwr.c \
        libft/ft_splitwhitespace.c \
        libft/get_next_line.c \
        libft/ft_strjoinf.c \
        libft/ft_strjoins.c \


HEADER = include/lemin.h

HEADER += libft/libft.h libft/get_next_line.h

CFLAGS =  -g3 -Wall -Werror -Wextra

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
