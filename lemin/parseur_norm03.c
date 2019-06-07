/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:04:25 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 18:11:42 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int		room_link(t_ressources *map, char *line)
{
	char		**str;
	t_tube		*tu;
	t_tube		*tmp;

	tmp = NULL;
	tu = map->tubes;
	str = ft_strsplit(line, '-');
	if (str[0] == NULL || str[1] == NULL)
		return (-1);
	if (check_format_tube(line) == -1)
		return (-1);
	if (map->tubes == NULL)
		map->tubes = add_links(map, str);
	else
	{
		while (tu->next != NULL)
			tu = tu->next;
		tmp = add_links(map, str);
		tu->next = tmp;
	}
	ft_free(str, 2);
	return (0);
}

void	innit_var(t_home *home)
{
	home->j = 0;
	home->i = 0;
	home->start = 0;
	home->end = 0;
}

void	who_fd(t_home *home, int ac, char **av)
{
	if (ac == 2)
		home->fd = open(av[1], O_RDONLY);
	else
		home->fd = 0;
}

int		part_tow(t_cellules *room, t_ressources *map)
{
	if (map->hm->start == 1)
	{
		map->debut = room;
		map->hm->start = 0;
	}
	else if (map->hm->end == 1)
	{
		map->fin = room;
		map->hm->end = 0;
	}
	return (0);
}

int		create_room(t_cellules *room, t_cellules *begin, char *line,
		t_ressources *map)
{
	map->hm->j++;
	if (map->cellules == NULL)
	{
		map->cellules = add_room(map->cellules);
		room = map->cellules;
		if (number_of_room(line, map->cellules) == -1)
			map->error = 2;
	}
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		room = add_room(room);
		begin->next = room;
	}
	if (map->hm->start == 1 || map->hm->end == 1)
		part_tow(room, map);
	if ((number_of_room(line, room) == -1) || map->error == 2 ||
	(map->hm->j != 0 && check_name_of_room(room, begin) == -1))
	{
		map->error = 2;
		return (-1);
	}
	return (0);
}
