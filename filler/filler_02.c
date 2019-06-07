/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:17:15 by arbib             #+#    #+#             */
/*   Updated: 2018/10/05 16:32:43 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*ft_check_piece(t_plateau *pl)
{
	char		*tmp;
	char		*str;

	get_next_line(0, &str);
	tmp = str;
	while (*tmp)
	{
		if (*tmp != '.' && *tmp != '*')
			return (NULL);
		if (*tmp == '*')
			pl->piece->nb_etoile++;
		tmp++;
	}
	if ((int)ft_strlen(str) != pl->piece->size_y)
		return (NULL);
	return (str);
}

int				ft_get_pc(t_plateau *pl)
{
	char		*str;
	int			i;

	i = 0;
	if (!(pl->piece->pie = (char **)ft_memalloc(sizeof(char *)
				* pl->piece->size_x + 1)))
		return (0);
	while (i < pl->piece->size_x)
	{
		pl->piece->pie[i] = (char *)ft_memalloc(pl->piece->size_y + 1);
		if ((str = ft_check_piece(pl)) == NULL)
			return (0);
		ft_strcpy(pl->piece->pie[i], str);
		i++;
		free(str);
	}
	return (1);
}

char			*ft_check_plat(t_plateau *pl)
{
	char		*str;
	char		*s;

	get_next_line(0, &str);
	s = (char *)ft_memalloc(pl->size_y + 1);
	if (ft_chck_char(str) != 1)
		return (NULL);
	if ((int)ft_strlen(str) - 4 != ((pl->size_y)))
		return (NULL);
	ft_strcpy(s, &str[4]);
	free(str);
	return (s);
}

int				ft_get_pl(t_plateau *pl)
{
	char		*str;
	int			i;

	i = 0;
	if (!(pl->plat = (char **)ft_memalloc(sizeof(char *) * pl->size_x + 1)))
		return (0);
	while (i < pl->size_x)
	{
		pl->plat[i] = (char *)ft_memalloc(pl->size_y + 1);
		if ((str = ft_check_plat(pl)) == NULL)
			return (0);
		ft_strcpy(pl->plat[i], str);
		i++;
		free(str);
	}
	return (1);
}
