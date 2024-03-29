/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:06:33 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 22:14:25 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(c = (ft_memalloc(len + 1))))
		return (NULL);
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	return (c);
}
