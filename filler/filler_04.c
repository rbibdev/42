/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:17:04 by arbib             #+#    #+#             */
/*   Updated: 2018/10/10 12:56:14 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_check_pos_bis(t_plateau *pl, int i, int j)
{
	if (pl->plat[i - pl->piece->x_min]
		[j + pl->size_y - pl->piece->y_min] == '.')
		pl->piece->nb_etoile_b++;
}

int				ft_check_pos_2(t_plateau *pl, int i, int j, int t)
{
	if (i - pl->piece->x_min <= pl->size_x && j - pl->piece->y_min <= pl->size_y
		&& i - pl->piece->x_min >= 0 && j - pl->piece->y_min >= 0)
	{
		if (pl->plat[i - pl->piece->x_min]
			[j - pl->piece->y_min] == pl->letter)
			t++;
		if (pl->plat[i - pl->piece->x_min]
			[j - pl->piece->y_min] == pl->letter_advers)
			return (-1);
		if (pl->plat[i - pl->piece->x_min][j - pl->piece->y_min] == '.')
			pl->piece->nb_etoile_b++;
	}
	return (t);
}

int				ft_check_pos(t_plateau *pl, int i, int j)
{
	int			k;
	int			m;

	pl->t = 0;
	k = -1;
	while (++k < pl->piece->size_x)
	{
		m = -1;
		while (++m < pl->piece->size_y)
		{
			if (pl->piece->pie[k][m] == '*' && i + (k - pl->piece->x_min) <
				pl->size_x && j + (m - pl->piece->y_min) < pl->size_y)
			{
				if (j + m < 0)
					ft_check_pos_bis(pl, i + k, m + j);
				if (j + m >= 0)
					pl->t = ft_check_pos_2(pl, i + k, j + m, pl->t);
				if (pl->t == -1)
					return (0);
			}
		}
	}
	if (pl->piece->nb_etoile - 1 != pl->piece->nb_etoile_b)
		return (0);
	return (pl->t);
}

void			ft_print_res(t_plateau *pl)
{
	ft_putnbr_fd(pl->x_me, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(pl->y_me, 1);
	ft_putchar_fd('\n', 1);
}
