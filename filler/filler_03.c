/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:17:24 by arbib             #+#    #+#             */
/*   Updated: 2018/10/05 16:29:24 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_get_adv(t_plateau *pl)
{
	int			i;
	int			j;

	i = 0;
	while (i < pl->size_x)
	{
		j = 0;
		while (j < pl->size_y)
		{
			if (pl->plat[i][j] == pl->letter_advers)
			{
				pl->x_adv = i;
				pl->y_adv = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_get_me(t_plateau *pl)
{
	int			i;
	int			j;

	i = 0;
	while (i < pl->size_x)
	{
		j = 0;
		while (j < pl->size_y)
		{
			if (pl->plat[i][j] == pl->letter)
			{
				pl->x_me = i;
				pl->y_me = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_get_best(t_plateau *pl)
{
	int			i;
	int			j;

	i = 0;
	while (i < pl->size_x)
	{
		j = 0;
		while (j < pl->size_y)
		{
			if (pl->plat[i][j] != pl->plat_bis[i][j] &&
				pl->plat[i][j] == pl->letter_advers &&
				i <= pl->size_x && j <= pl->size_y)
			{
				pl->best_x = i;
				pl->best_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			ft_minxy(t_plateau *pl)
{
	int			i;
	int			j;

	i = 0;
	while (i < pl->piece->size_x)
	{
		j = 0;
		while (j < pl->piece->size_y)
		{
			if (pl->piece->pie[i][j] == '*')
			{
				pl->piece->x_min = i;
				pl->piece->y_min = j;
				break ;
			}
			j++;
		}
		if (pl->piece->pie[i][j] == '*')
			break ;
		i++;
	}
}

void			ft_free_ta_race(char **tab, int t)
{
	int			i;

	i = 0;
	while (i < t)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
