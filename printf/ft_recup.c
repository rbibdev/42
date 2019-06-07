/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:35:15 by arbib             #+#    #+#             */
/*   Updated: 2018/02/21 05:40:47 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_get_flags(char **str, t_arg *args)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
	{
		if (**str == '#')
			args->tr_prefix = 1;
		if (**str == '0')
			args->tr_zero = 1;
		if (**str == '-')
			args->tr_pad_droite = 1;
		if (**str == '+')
			args->tr_sign = 1;
		if (**str == ' ')
			args->tr_espace = 1;
		(*str)++;
		if (args->tr_pad_droite == 1)
			args->tr_zero = 0;
		return (ft_get_flags(str, args));
	}
	else
		return (*str);
}

char	*ft_get_width(char **str, t_arg *args, va_list *ap)
{
	int	ar;

	while (**str == '*' || ft_isdigit(**str))
	{
		if (**str == '*')
		{
			(*str)++;
			ar = va_arg(*ap, int);
			if (ar < 0)
				args->tr_pad_droite = 1;
			args->width = ar < 0 ? -ar : ar;
			args->tr_width = 1;
		}
		if (ft_isdigit((**str)))
		{
			args->tr_width = 1;
			args->width = 0;
			while (ft_isdigit(**str))
				args->width = args->width * 10 + (*(*str)++ - '0');
		}
	}
	return (*str);
}

char	*ft_get_precision(char **str, t_arg *args, va_list *ap)
{
	int pr;

	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			(*str)++;
			if ((pr = va_arg(*ap, int)) >= 0)
			{
				args->tr_precision = 1;
				args->precision = pr;
			}
			return (*str);
		}
		else
		{
			while (ft_isdigit(**str))
				args->precision = args->precision * 10 + (*(*str)++ - '0');
			args->tr_precision = 1;
			return (*str);
		}
	}
	else
		return (*str);
}

char	*ft_get_length(char **str, t_arg *args)
{
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		args->length = hh;
		return (*str += 2);
	}
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		args->length = ll;
		return (*str += 2);
	}
	else if (**str == 'h' || **str == 'l' || **str == 'j' ||
					**str == 'z')
	{
		if (**str == 'h' && args->length != j && args->length != z)
			args->length = h;
		else if (**str == 'l')
			args->length = l;
		else if (**str == 'j')
			args->length = j;
		else if (**str == 'z')
			args->length = z;
		return ((*str)++);
	}
	else
		return (*str);
}

t_conv	ft_printf_get_conv(char c)
{
	static t_conv	*conv = NULL;

	if (conv == NULL)
	{
		conv = ft_memalloc(sizeof(*conv) * 256);
		if (conv != NULL)
			ft_conv_maker(conv);
	}
	return (conv[(int)c]);
}
