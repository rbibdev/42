/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:28:56 by arbib             #+#    #+#             */
/*   Updated: 2017/11/07 19:29:00 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int nb;
	int i;

	i = 0;
	nb = 0;
	if (max < min || max == min)
		return (0);
	if (min >= 0)
		nb = max - min;
	if (min < 0)
		nb = max + (-min);
	tab = (int*)malloc(sizeof(int) * (nb + 1));
	while (nb > i)
	{
		tab[i] = min + i;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
