/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:17:04 by arbib             #+#    #+#             */
/*   Updated: 2018/10/10 12:56:14 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_print_best(t_best *t, int k, t_plateau *pl)
{
	int			x;
	int			y;

	pl->i = -1;
	x = pl->size_x;
	y = pl->size_y;
	while (++pl->i < k)
	{
		if ((((ft_abs(t[pl->i].best_x - pl->best_x) <= x &&
			ft_abs(t[pl->i].best_y - pl->best_y) <= y)) ||
			ft_abs(t[pl->i].best_x - pl->best_x) <= x))
		{
			x = ft_abs(t[pl->i].best_x - pl->best_x);
			y = ft_abs(t[pl->i].best_y - pl->best_y);
			pl->x_me = t[pl->i].best_x;
			pl->y_me = t[pl->i].best_y;
		}
	}
	free(t);
	if (x == pl->size_x && y == pl->size_y)
		return (0);
	else
		ft_print_res(pl);
	return (1);
}

int				ft_print_best_bis(t_best *t, int k, t_plateau *pl)
{
	int			x;
	int			y;

	pl->i = -1;
	x = pl->size_x;
	y = pl->size_y;
	while (++pl->i < k)
	{
		if ((ft_abs(t[pl->i].best_y - pl->best_y) <= y
			|| ((ft_abs(t[pl->i].best_x - pl->best_x) <= x &&
			ft_abs(t[pl->i].best_y - pl->best_y) <= y)) ||
			ft_abs(t[pl->i].best_x - pl->best_x) <= x))
		{
			x = ft_abs(t[pl->i].best_x - pl->best_x);
			y = ft_abs(t[pl->i].best_y - pl->best_y);
			pl->x_me = t[pl->i].best_x;
			pl->y_me = t[pl->i].best_y;
		}
	}
	free(t);
	if (x == pl->size_x && y == pl->size_y)
		return (0);
	else
		ft_print_res(pl);
	return (1);
}

int				ft_print_best_choix(t_best *t, int k, t_plateau *pl)
{
	if (pl->size_y <= 17)
		return (ft_print_best_bis(t, k, pl));
	else
		return (ft_print_best(t, k, pl));
}
