/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:28:04 by arbib             #+#    #+#             */
/*   Updated: 2017/11/07 19:28:08 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
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
	if (!(c = (char*)malloc(sizeof(char) * (taille))))
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
