/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:59:51 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:15:29 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

void	ft_free(char **tab, int t)
{
	int	i;

	i = 0;
	while (i < t)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

int		check_name_of_room(t_cellules *room, t_cellules *begin)
{
	int i;

	i = 0;
	while (begin != NULL)
	{
		if (!ft_strcmp(begin->nom, room->nom))
			i++;
		if (i == 2)
			return (-1);
		begin = begin->next;
	}
	return (0);
}

int		my_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		my_isdigitstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-')
			i++;
		if (my_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		number_of_ants(char *str, t_ressources *map)
{
	int i;

	i = 0;
	map->nb_fourm = ft_atoi(str);
	if (map->nb_fourm <= 0 || map->nb_fourm > 2147483646)
		return (1);
	return (0);
}
