/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 23:30:31 by arbib             #+#    #+#             */
/*   Updated: 2018/03/05 14:14:35 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int		ft_printf_chck(char **str, t_arg *args, va_list *ap)
{
	if (ft_get_flags(str, args) == NULL)
		return (-1);
	if (ft_get_width(str, args, ap) == NULL)
		return (-1);
	if (ft_get_precision(str, args, ap) == NULL)
		return (-1);
	if (ft_get_length(str, args) == NULL)
		return (-1);
	if (ft_get_flags(str, args) == NULL)
		return (-1);
	if (ft_get_length(str, args) == NULL)
		return (-1);
	while (**str == 'h' || **str == 'l' || **str == 'j' ||
			**str == 'z' || **str == '#' || **str == '*' ||
			**str == '.' || (**str == '+' && args->tr_sign == 1) ||
			ft_isdigit(**str))
		(*str)++;
	if (ft_get_flags(str, args) == NULL)
		return (-1);
	return (1);
}

static ssize_t	ft_printf_get(char **str, t_arg *args, va_list *ap, size_t n)
{
	ssize_t		retour;
	t_conv		conv;

	if ((*(++*str)) == '\0')
		return (0);
	conv = NULL;
	if ((ft_printf_chck(str, args, ap)) == -1)
		return (-1);
	if (**str == '\0')
		return (0);
	if ((conv = ft_printf_get_conv(**str)) == NULL)
		conv = ft_printf_conv_null;
	if (**str == 'n')
		retour = ft_printf_conv_charswritten(n, ap);
	else
		retour = conv(str, args, ap);
	(*str)++;
	return (retour);
}

static int		ft_printf_exc(va_list *ap, const char *str, size_t n)
{
	char		*start;
	t_arg		args;
	ssize_t		trait_len;

	start = ft_strchr(str, '%');
	if (*str == '\0')
		return (n);
	if (start == NULL)
	{
		ft_putstr(str);
		return (n + ft_strlen(str));
	}
	else if (start > str)
	{
		ft_putnstr(str, start - str);
		return (ft_printf_exc(ap, start, n + (start - str)));
	}
	else
	{
		ft_bzero(&args, sizeof(args));
		if ((trait_len = ft_printf_get((char**)&str, &args, ap, n)) == -1)
			return (-1);
		else
			return (ft_printf_exc(ap, str, trait_len + n));
	}
}

int				ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			n;

	if (str == '\0')
		return (0);
	n = 0;
	va_start(ap, str);
	n = ft_printf_exc(&ap, str, 0);
	va_end(ap);
	return (n);
}
