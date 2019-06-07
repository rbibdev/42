/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:14:20 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:34:49 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		*ft_memalloc(size_t size)
{
	char	*c;

	if ((c = malloc(size)))
	{
		ft_bzero(c, size);
		return (c);
	}
	else
		return (NULL);
}
