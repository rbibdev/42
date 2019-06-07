/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:07:00 by arbib             #+#    #+#             */
/*   Updated: 2017/11/20 01:06:43 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*c;

	if ((c = ft_memalloc(size + 1)))
	{
		while (size > 0)
		{
			c[size] = '\0';
			size--;
		}
		return (c);
	}
	else
		return (NULL);
}
