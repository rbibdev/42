/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:37:43 by arbib             #+#    #+#             */
/*   Updated: 2018/10/05 16:28:26 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_put_piece(t_plateau *pl)
{
	int			i;
	int			j;
	int			k;
	t_best		*t;

	k = 0;
	i = -1;
	j = 0;
	t = ft_memalloc(sizeof(t) * 10000);
	ft_get_best(pl);
	while (++i < pl->size_x)
	{
		j = -pl->piece->size_y - 1;
		while (j++ < pl->size_y)
		{
			pl->piece->nb_etoile_b = 0;
			if (ft_check_pos(pl, i, j) == 1)
			{
				t[k].best_x = i - (pl->piece->x_min);
				t[k].best_y = j - (pl->piece->y_min);
				k++;
			}
		}
	}
	return (ft_print_best_choix(t, k, pl));
}

int				ft_filler(t_plateau *pl)
{
	char		*s;

	s = NULL;
	get_next_line(0, &s);
	free(s);
	get_next_line(0, &s);
	free(s);
	if (ft_get_pl(pl) == 0)
		return (-1);
	if (ft_get_xy_pc(pl) == 0)
		return (-1);
	if (ft_get_pc(pl) == 0)
		return (-1);
	ft_minxy(pl);
	return (0);
}

int				ft_filler_first(t_plateau *pl)
{
	ft_get_lettre(pl);
	if (ft_get_xy_pl(pl) == 0)
		return (-1);
	if (ft_get_pl(pl) == 0)
		return (-1);
	if (ft_get_xy_pc(pl) == 0)
		return (-1);
	if (ft_get_pc(pl) == 0)
		return (-1);
	ft_minxy(pl);
	return (0);
}

int				main(void)
{
	t_plateau	pl;

	ft_bzero(&pl, sizeof(t_plateau));
	pl.piece = ft_memalloc(sizeof(t_piece));
	ft_filler_first(&pl);
	pl.plat_bis = pl.plat;
	ft_put_piece(&pl);
	ft_free_ta_race(pl.piece->pie, pl.piece->size_x);
	pl.piece->nb_etoile = 0;
	while (1)
	{
		ft_filler(&pl);
		if (ft_put_piece(&pl) == 0)
		{
			ft_putstr_fd("0 0\n", 1);
			break ;
		}
		pl.piece->nb_etoile = 0;
		ft_free_ta_race(pl.piece->pie, pl.piece->size_x);
		ft_free_ta_race(pl.plat_bis, pl.size_x);
		pl.plat_bis = pl.plat;
	}
	ft_free_ta_race(pl.plat, pl.size_x);
	ft_free_ta_race(pl.plat_bis, pl.size_x);
	return (0);
}
