/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 14:14:23 by arbib             #+#    #+#             */
/*   Updated: 2017/11/15 19:57:21 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*c;
	int		taille;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	taille = i + 1;
	if (!(c = (char*)ft_memalloc(sizeof(char) * (taille))))
		return (0);
	i = 0;
	while (taille > 0 && *src)
	{
		c[i] = src[i];
		i++;
		taille--;
	}
	return (c);
}
