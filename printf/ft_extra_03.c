/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 02:11:41 by arbib             #+#    #+#             */
/*   Updated: 2018/02/21 03:27:35 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void				ft_conv_maker(t_conv *conv)
{
	conv['%'] = &ft_printf_conv_echap;
	conv['s'] = &ft_printf_conv_str;
	conv['S'] = &ft_printf_conv_wchars;
	conv['d'] = &ft_printf_conv_int;
	conv['D'] = &ft_printf_conv_long;
	conv['i'] = &ft_printf_conv_int;
	conv['o'] = &ft_printf_conv_octal;
	conv['O'] = &ft_printf_conv_long;
	conv['u'] = &ft_printf_conv_unsigned;
	conv['U'] = &ft_printf_conv_long;
	conv['x'] = &ft_printf_conv_hex;
	conv['X'] = &ft_printf_conv_hex;
	conv['c'] = &ft_printf_conv_char;
	conv['C'] = &ft_printf_conv_wchar;
	conv['b'] = &ft_printf_conv_binary;
	conv['p'] = &ft_printf_conv_pointeur;
}

size_t				ft_nstrlen(const char *str, size_t max_len)
{
	size_t			i;

	i = 0;
	while (*str++ && i < max_len)
		i++;
	return (i);
}

size_t				ft_wstrlen(wchar_t *str)
{
	size_t			i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t				ft_printf_put_prefix(uintmax_t nbr,
						char *base, t_arg *arg, char *prefix)
{
	unsigned		nbr_len;
	size_t			nbr_retire;

	nbr_len = ft_printf_calc_nbrstrlen(nbr, base, NULL, arg) +
		ft_strlen(prefix);
	nbr_retire = ft_strlen(prefix);
	if (arg->tr_width && !arg->tr_pad_droite && !arg->tr_zero)
	{
		ft_printf_width_pad(nbr_len, arg->width, ' ');
		nbr_retire += ft_max(arg->width - nbr_len, 0);
		arg->tr_width = 0;
	}
	else if (arg->tr_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_printf_uint(nbr, arg, base, NULL) + nbr_retire);
}

size_t				get_wstr_len(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (get_wstr_len(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (get_wstr_len(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (get_wstr_len(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (get_wstr_len(str + 1, precision - 4, i + 4));
	else
		return (i);
}
