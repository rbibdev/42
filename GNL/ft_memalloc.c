/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:14:20 by arbib             #+#    #+#             */
/*   Updated: 2017/11/19 16:24:30 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*c;

	if ((c = malloc(sizeof(char) * size)))
	{
		ft_bzero(c, size);
		return (c);
	}
	else
		return (NULL);
}
