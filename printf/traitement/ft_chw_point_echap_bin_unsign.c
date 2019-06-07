/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chw_point_echap_bin_unsign.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 04:16:39 by arbib             #+#    #+#             */
/*   Updated: 2018/02/17 04:17:52 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t				ft_printf_conv_echap(char **str, t_arg *arg, va_list *ap)
{
	(void)str;
	(void)arg;
	(void)ap;
	if (arg->tr_width && !arg->tr_pad_droite)
		ft_printf_width_pad(1, arg->width, arg->tr_zero ? '0' : ' ');
	ft_putchar('%');
	if (arg->tr_width && arg->tr_pad_droite)
		ft_printf_width_pad(1, arg->width, ' ');
	return (arg->tr_width ? ft_max(arg->width, 1) : 1);
}

ssize_t				ft_printf_conv_charswritten(size_t val, va_list *ap)
{
	int *t;
	int	nbr;

	t = va_arg(*ap, int*);
	nbr = (int)val;
	*t = nbr;
	return (val + ft_printf_nbrlen((uintmax_t)val, "0123456789"));
}

ssize_t				ft_printf_conv_pointeur(char **str, t_arg *arg,
						va_list *ap)
{
	char			*base;
	uintmax_t		nbr;

	(void)str;
	arg->length = z;
	if (arg->tr_precision)
		arg->tr_zero = 0;
	base = "0123456789abcdef";
	nbr = ft_printf_unsigned_length(ap, arg);
	return (ft_printf_put_prefix(nbr, base, arg, "0x"));
}

ssize_t				ft_printf_conv_unsigned(char **str, t_arg *arg,
						va_list *ap)
{
	uintmax_t		nbr;

	(void)str;
	nbr = ft_printf_unsigned_length(ap, arg);
	return (ft_printf_uint(nbr, arg, "0123456789", NULL));
}

ssize_t				ft_printf_conv_binary(char **str, t_arg *arg, va_list *ap)
{
	uintmax_t		nbr;

	(void)str;
	nbr = ft_printf_unsigned_length(ap, arg);
	return (ft_printf_uint(nbr, arg, "01", "0b"));
}
