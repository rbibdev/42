/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str_wchar_wstr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:03:33 by arbib             #+#    #+#             */
/*   Updated: 2018/02/21 04:39:59 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t			ft_printf_conv_wchar(char **str, t_arg *arg, va_list *ap)
{
	wchar_t		chr;
	unsigned	chr_len;

	(void)str;
	chr = (wchar_t)va_arg(*ap, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->tr_width && !arg->tr_pad_droite)
		ft_printf_width_pad(chr_len, arg->width, arg->tr_zero ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->tr_width && arg->tr_pad_droite)
		ft_printf_width_pad(chr_len, arg->width, arg->tr_zero ? '0' : ' ');
	return (arg->tr_width ? ft_max(chr_len, arg->width) : chr_len);
}

ssize_t			ft_printf_conv_char(char **str, t_arg *arg, va_list *ap)
{
	(void)str;
	if (arg->length == l)
		return (ft_printf_conv_wchar(str, arg, ap));
	else
	{
		if (arg->tr_width && !arg->tr_pad_droite)
			ft_printf_width_pad(1, arg->width, arg->tr_zero ? '0' : ' ');
		ft_putchar(va_arg(*ap, int));
		if (arg->tr_width && arg->tr_pad_droite)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->tr_width ? ft_max(arg->width, 1) : 1);
	}
}

ssize_t			ft_printf_conv_str(char **str, t_arg *arg, va_list *ap)
{
	char		*s;
	size_t		strlen;

	if (arg->length == l)
		return (ft_printf_conv_wchars(str, arg, ap));
	else
	{
		s = va_arg(*ap, char*);
		if (s == NULL)
			s = "(null)";
		strlen = arg->tr_precision ? ft_nstrlen(s, arg->precision) :
				ft_strlen(s);
		if (arg->tr_width && !arg->tr_pad_droite)
			ft_printf_width_pad(strlen, arg->width, arg->tr_zero ?
					'0' : ' ');
		ft_putnstr(s, strlen);
		if (arg->tr_width && arg->tr_pad_droite)
			ft_printf_width_pad(strlen, arg->width, ' ');
		return (arg->tr_width ? ft_max(strlen, arg->width) : strlen);
	}
}

ssize_t			ft_printf_conv_wchars(char **str, t_arg *arg, va_list *ap)
{
	wchar_t		*s;
	size_t		strlen;

	(void)str;
	(void)arg;
	s = va_arg(*ap, wchar_t*);
	if (s == NULL)
		s = L"(null)";
	strlen = arg->tr_precision ? get_wstr_len(s, arg->precision, 0) :
			ft_wstrlen(s);
	if (arg->tr_width && !arg->tr_pad_droite)
		ft_printf_width_pad(strlen, arg->width, arg->tr_zero ? '0' : ' ');
	ft_putnwstr(s, strlen + 1);
	if (arg->tr_width && arg->tr_pad_droite)
		ft_printf_width_pad(strlen, arg->width, ' ');
	return (arg->tr_width ? ft_max(strlen, arg->width) : strlen);
}

ssize_t			ft_printf_conv_null(char **str, t_arg *arg, va_list *ap)
{
	(void)ap;
	if (arg->tr_width && !arg->tr_pad_droite)
		ft_printf_width_pad(1, arg->width, arg->tr_zero ? '0' : ' ');
	ft_putchar(**str);
	if (arg->tr_width && arg->tr_pad_droite)
		ft_printf_width_pad(1, arg->width, ' ');
	return (arg->tr_width ? ft_max(arg->width, 1) : 1);
}
