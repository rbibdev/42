/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:17:32 by arbib             #+#    #+#             */
/*   Updated: 2018/10/05 16:32:49 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_chck_char(char *str)
{
	size_t			i;

	i = 4;
	while (i < ft_strlen(str) && str[i] != '\0' && str != NULL)
	{
		if (str[i] != '.' && str[i] != 'X' && str[i] != 'O' &&
				str[i] != 'o' && str[i] != 'x')
			return (0);
		i++;
	}
	return (1);
}

int				ft_get_xy_pc(t_plateau *pl)
{
	char		*str;
	char		**tab;

	get_next_line(0, &str);
	tab = ft_splitwhitespace(str);
	if (ft_strcmp(tab[0], "Piece") != 0)
		return (0);
	if (ft_isdigit(tab[1]) == 1)
		pl->piece->size_x = ft_atoi(tab[1]);
	else
		return (0);
	pl->piece->size_y = ft_atoi(tab[2]);
	free(str);
	ft_free_ta_race(tab, 3);
	return (1);
}

int				ft_get_xy_pl(t_plateau *pl)
{
	char		*str;
	char		**tab;

	get_next_line(0, &str);
	tab = ft_splitwhitespace(str);
	pl->size_x = ft_atoi(tab[1]);
	pl->size_y = ft_atoi(tab[2]);
	free(str);
	ft_free_ta_race(tab, 3);
	get_next_line(0, &str);
	free(str);
	return (1);
}

void			ft_get_lettre(t_plateau *pl)
{
	char		*str;
	int			i;

	i = 3;
	get_next_line(0, &str);
	if (str[10] == '1')
	{
		pl->letter = 'O';
		pl->letter_advers = 'X';
	}
	else
	{
		pl->letter = 'X';
		pl->letter_advers = 'O';
	}
	free(str);
}

int				ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
