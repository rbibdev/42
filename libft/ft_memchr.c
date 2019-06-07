/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:51:04 by arbib             #+#    #+#             */
/*   Updated: 2017/11/15 21:49:17 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sr;

	sr = (unsigned char*)s;
	while (n--)
	{
		if (*sr == (unsigned char)c)
			return (sr);
		sr++;
	}
	return (NULL);
}
