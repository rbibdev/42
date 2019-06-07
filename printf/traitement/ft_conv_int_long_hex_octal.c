/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_long_hex_octal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 04:14:48 by arbib             #+#    #+#             */
/*   Updated: 2018/02/17 04:18:22 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t				ft_printf_uint(uintmax_t nbr, t_arg *arg, char *base,
						char *prefix)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = ft_printf_nbrlen(nbr, base);
	if (arg->tr_width && !arg->tr_pad_droite && arg->tr_zero)
	{
		if (arg->tr_precision)
			arg->precision = ft_max(arg->width, arg->precision);
		else if (!arg->tr_precision && prefix != NULL)
			arg->precision = ft_max(arg->width - ft_strlen(prefix), nbr_len);
		else if (!arg->tr_precision && prefix == NULL)
			arg->precision = ft_max(arg->width, nbr_len);
		arg->tr_precision = 1;
		arg->tr_width = 0;
	}
	nbrstrlen = ft_printf_calc_nbrstrlen(nbr, base, prefix, arg);
	if (arg->tr_width && !arg->tr_pad_droite)
		ft_printf_width_pad(nbrstrlen, arg->width, ' ');
	if (arg->tr_prefix && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbr_base_prefix(nbr, base, arg, nbr_len);
	if (arg->tr_width && arg->tr_pad_droite)
		ft_printf_width_pad(nbrstrlen, arg->width, ' ');
	return (arg->tr_width ? ft_max(nbrstrlen, arg->width) : nbrstrlen);
}

ssize_t				ft_printf_conv_int(char **str, t_arg *arg, va_list *ap)
{
	intmax_t		nbr;
	char			*prefix;

	(void)str;
	if (arg->tr_precision)
		arg->tr_zero = 0;
	nbr = ft_printf_signed_length(ap, arg);
	if (nbr < 0 || arg->tr_sign || arg->tr_espace)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->tr_sign)
			prefix = "+";
		else if (arg->tr_espace)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_put_prefix(nbr, "0123456789", arg, prefix));
	}
	else
		return (ft_printf_uint(nbr, arg, "0123456789", NULL));
}

ssize_t				ft_printf_conv_hex(char **str, t_arg *arg, va_list *ap)
{
	uintmax_t		nbr;

	nbr = ft_printf_unsigned_length(ap, arg);
	if (**str == 'X' && arg->tr_prefix)
		return (ft_printf_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else if (**str == 'x' && arg->tr_prefix)
		return (ft_printf_uint(nbr, arg, "0123456789abcdef", "0x"));
	if (**str == 'X' && !arg->tr_prefix)
		return (ft_printf_uint(nbr, arg, "0123456789ABCDEF", NULL));
	else
		return (ft_printf_uint(nbr, arg, "0123456789abcdef", NULL));
}

ssize_t				ft_printf_conv_long(char **str, t_arg *arg, va_list *ap)
{
	arg->length = l;
	return (ft_printf_get_conv(ft_tolower(**str))(str, arg, ap));
}

ssize_t				ft_printf_conv_octal(char **str, t_arg *arg, va_list *ap)
{
	uintmax_t		nbr;

	(void)str;
	nbr = ft_printf_unsigned_length(ap, arg);
	if (arg->tr_prefix && nbr == 0 &&
				arg->tr_precision && arg->precision == 0)
	{
		if (arg->tr_width && !arg->tr_pad_droite)
			ft_printf_width_pad(1, arg->width, arg->tr_zero ? '0' : ' ');
		ft_putstr("0");
		if (arg->tr_width && arg->tr_pad_droite)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->tr_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->tr_prefix && nbr != 0)
	{
		arg->tr_precision = 1;
		arg->precision = ft_max(arg->precision,
				ft_printf_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_printf_uint(nbr, arg, "01234567", NULL));
}
