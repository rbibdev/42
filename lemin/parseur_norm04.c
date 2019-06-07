/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:04:33 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 15:04:55 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int		part_one(t_cellules *room, t_cellules *begin, char *line,
		t_ressources *map)
{
	if (map->hm->i == 0 && my_isdigitstr(line) == 0)
	{
		if (number_of_ants(line, map) == 1)
		{
			map->error = 1;
			return (-1);
		}
		map->hm->i++;
	}
	else if (map->hm->i != 0 && map->hm->i != 2
			&& line[0] != '#' && search_char(' ', line) == 1
			&& search_char('-', line) == 0 && search_char('L', line) == 0 &&
			create_room(room, begin, line, map) == -1)
		return (-1);
	else if (map->hm->i != 0 && line[0] != '#'
			&& search_char('-', line) == 1 && search_char(' ', line) == 0)
	{
		map->hm->i = 2;
		if (room_link(map, line) == -1)
		{
			map->error = 4;
			return (-1);
		}
	}
	return (0);
}

void	choice_of_command_start_or_and(char *line, t_ressources *map)
{
	if (order_of_lemin(line) == 0)
		map->hm->start = 1;
	else if (order_of_lemin(line) == 1)
		map->hm->end = 1;
	else
		map->error = 5;
}

int		parseur(char *line, t_ressources *map)
{
	t_cellules *room;
	t_cellules *begin;

	begin = map->cellules;
	room = NULL;
	if ((map->hm->i == 0 && my_isdigitstr(line) == 0) ||
	(map->hm->i != 0 && map->hm->i != 2 && line[0] != '#' &&
	search_char(' ', line) == 1 && search_char('-', line) == 0 &&
	search_char('L', line) == 0) || (map->hm->i != 0 && line[0] != '#'
	&& search_char('-', line) == 1 && search_char(' ', line) == 0))
	{
		if (part_one(room, begin, line, map) == -1)
			return (-1);
	}
	else if (map->hm->i != 0 && map->hm->i != 2
			&& line[0] == '#' && line[1] == '#')
		choice_of_command_start_or_and(line, map);
	else if (!(line[0] == '#' && line[1] != '#'))
		map->error = 6;
	if (map->error == 5 || map->error == 6)
		return (-1);
	return (0);
}

int		check_line(char *line)
{
	if (ft_strlen(line) == 0 || (ft_strlen(line) == 1 && line[0] == '\n'))
		return (-1);
	return (0);
}

void	init_var_s(t_ressources *map)
{
	map->hm = ft_memalloc(sizeof(t_home));
	innit_var(map->hm);
	map->tubes = NULL;
	map->cellules = NULL;
}
