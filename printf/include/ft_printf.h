/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 23:30:34 by arbib             #+#    #+#             */
/*   Updated: 2018/02/21 05:41:28 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
****************************************************************************
**********************************Structure*********************************
****************************************************************************
*/

typedef struct		s_arg
{
	int				tr_prefix : 1;
	int				tr_zero : 1;
	int				tr_pad_droite : 1;
	int				tr_sign : 1;
	int				tr_espace : 1;
	int				tr_width : 1;
	int				tr_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

/*
****************************************************************************
**********************************recuperation******************************
****************************************************************************
*/

char				*ft_get_flags(char **str, t_arg *args);
char				*ft_get_width(char **str, t_arg *args, va_list *ap);
char				*ft_get_precision(char **str, t_arg *args, va_list *ap);
char				*ft_get_length(char **str, t_arg *args);
typedef ssize_t		(*t_conv)(char**, t_arg*, va_list*);
t_conv				ft_printf_get_conv(char c);

/*
****************************************************************************
**********************************conversion********************************
****************************************************************************
*/

ssize_t				ft_printf_conv_echap(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_str(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_wchar(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_wchars(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_char(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_null(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_charswritten(size_t	val, va_list *ap);
ssize_t				ft_printf_conv_pointeur(char **str, t_arg *args,
						va_list *ap);
ssize_t				ft_printf_conv_int(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_octal(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_long(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_unsigned(char **str, t_arg *args,
						va_list *ap);
ssize_t				ft_printf_conv_long(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_hex(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_conv_binary(char **str, t_arg *args, va_list *ap);
ssize_t				ft_printf_uint(uintmax_t nbr, t_arg *arg, char *base,
						char *prefix);

/*
****************************************************************************
**********************************Extra01***********************************
****************************************************************************
*/

intmax_t			ft_printf_signed_length(va_list *ap, t_arg *args);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
uintmax_t			ft_printf_unsigned_length(va_list *ap, t_arg *args);
unsigned int		ft_printf_calc_nbrstrlen(uintmax_t nbr, char *base,
						char *s, t_arg *args);
void				ft_putnbr_base_prefix(uintmax_t nbr, char *base,
						t_arg *arg, unsigned nbr_len);

/*
****************************************************************************
**********************************Extra02***********************************
****************************************************************************
*/

void				ft_putwchar(wchar_t c);
void				ft_putnstr(char const *str, size_t len);
void				ft_putwstr(wchar_t const *str);
void				ft_putnwstr(const wchar_t *str, size_t len);
void				ft_printf_width_pad(int nbrstrlen, int width, char padwith);

/*
****************************************************************************
**********************************Extra02***********************************
****************************************************************************
*/

size_t				ft_nstrlen(const char *str, size_t max_len);
size_t				ft_wstrlen(wchar_t *str);
size_t				get_wstr_len(wchar_t *str, int precision, size_t i);
ssize_t				ft_printf_put_prefix(uintmax_t nbr,
						char *base, t_arg *args, char *prefix);
void				ft_conv_maker(t_conv *conv);
#endif
