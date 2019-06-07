/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:18:36 by arbib             #+#    #+#             */
/*   Updated: 2017/11/15 19:36:29 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dest,
								const void *src, int c, size_t n)
{
	const unsigned char	*sr;
	unsigned char		*ds;

	ds = (unsigned char*)dest;
	sr = (unsigned char*)src;
	while (n--)
	{
		if ((*ds++ = *sr++) == (unsigned char)c)
			return (ds);
	}
	return (NULL);
}
