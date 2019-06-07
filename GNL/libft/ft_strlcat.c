/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:30:03 by arbib             #+#    #+#             */
/*   Updated: 2017/11/17 00:31:28 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		j;
	const char	*s;
	char		*d;
	size_t		i;

	d = dest;
	s = src;
	i = n;
	while (*d != '\0' && i-- != 0)
		d++;
	j = d - dest;
	i = n - j;
	if (i == 0)
		return (j + ft_strlen(s));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (j + (s - src));
}
