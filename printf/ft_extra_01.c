/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 02:11:07 by arbib             #+#    #+#             */
/*   Updated: 2018/02/20 02:29:36 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

intmax_t			ft_printf_signed_length(va_list *ap, t_arg *args)
{
	intmax_t		nbr;

	nbr = va_arg(*ap, intmax_t);
	if (args->length == hh)
		nbr = (char)nbr;
	else if (args->length == h)
		nbr = (short int)nbr;
	else if (args->length == l)
		nbr = (long int)nbr;
	else if (args->length == ll)
		nbr = (long long int)nbr;
	else if (args->length == j)
		nbr = (intmax_t)nbr;
	else if (args->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

unsigned int		ft_printf_calc_nbrstrlen(uintmax_t nbr, char *base,
						char *p, t_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = ft_printf_nbrlen(nbr, base);
	if (nbr == 0 && arg->tr_precision && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->tr_precision)
		nbrstrlen = ft_max(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->tr_prefix && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}

uintmax_t			ft_printf_unsigned_length(va_list *args, t_arg *arg)
{
	uintmax_t		nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->length == hh)
		nbr = (unsigned char)nbr;
	else if (arg->length == h)
		nbr = (unsigned short int)nbr;
	else if (arg->length == l)
		nbr = (unsigned long int)nbr;
	else if (arg->length == ll)
		nbr = (unsigned long long int)nbr;
	else if (arg->length == j)
		nbr = (uintmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

void				ft_putnbr_base_prefix(uintmax_t nbr, char *base, t_arg *arg,
						unsigned nbr_len)
{
	if (arg->tr_precision)
		ft_printf_width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->tr_precision && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}
