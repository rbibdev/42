/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionnelles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimet <agimet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:37:39 by agimet            #+#    #+#             */
/*   Updated: 2017/12/18 12:12:11 by agimet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

t_coord		ft_inc_pos(t_coord pos)
{
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

void		ft_trait_1st(t_tetri *new, char *buff)
{
	new = ft_fill_coord(new, buff);
	new = ft_fill_min(new);
	new = ft_fill_size(new);
	new->letter = 'A';
	new->next = NULL;
}
