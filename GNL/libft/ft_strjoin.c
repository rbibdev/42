/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:18:50 by arbib             #+#    #+#             */
/*   Updated: 2017/12/02 19:44:37 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	t;
	size_t	l;
	int		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	t = ft_strlen(s1);
	l = ft_strlen(s2);
	if (!(c = malloc(sizeof(char) * (t + l + 1))))
		return (NULL);
	while (*s1)
	{
		c[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		c[i] = *s2;
		s2++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
