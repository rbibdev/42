/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:16:48 by arbib             #+#    #+#             */
/*   Updated: 2017/11/22 00:47:48 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_tab(char **tab, size_t l)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = 0;
	j = 1;
	while (++i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				c = tab[i];
				tab[i] = tab[j];
				tab[j] = c;
			}
			j++;
		}
	}
}
