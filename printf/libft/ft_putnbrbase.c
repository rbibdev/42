/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:34:39 by arbib             #+#    #+#             */
/*   Updated: 2018/02/16 08:21:41 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrbase(uintmax_t nbr, char *base)
{
	size_t	size_base;

	size_base = ft_strlen(base);
	if (nbr >= size_base)
	{
		ft_putnbrbase(nbr / size_base, base);
		ft_putnbrbase(nbr % size_base, base);
	}
	else
		ft_putchar(base[nbr]);
}
