/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:59:57 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:08:41 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

void			copy_line_in_map(t_ressources *map, char *line)
{
	if (map->map == NULL)
		map->map = ft_strdup("\0");
	map->map = realloc(map->map, ft_strlen(line) + ft_strlen(map->map) + 2);
	map->map = ft_strcat(map->map, line);
	map->map = ft_strcat(map->map, "\n");
}

t_cellules		*add_room(t_cellules *room)
{
	if (!(room = (t_cellules*)ft_memalloc(sizeof(t_cellules))))
		return (NULL);
	room->next = NULL;
	return (room);
}

int				search_char(char n, char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == n)
			return (1);
		i++;
	}
	return (0);
}

t_tube			*add_links(t_ressources *map, char **str)
{
	t_cellules	*cell;
	t_tube		*tu;

	cell = map->cellules;
	tu = (t_tube*)ft_memalloc(sizeof(t_tube));
	tu->cellule_dep = NULL;
	tu->cellule_arr = NULL;
	while (cell != NULL)
	{
		if (ft_strcmp(cell->nom, str[0]) == 0)
			tu->cellule_dep = cell;
		else if (ft_strcmp(cell->nom, str[1]) == 0)
			tu->cellule_arr = cell;
		cell = cell->next;
	}
	tu->next = NULL;
	return (tu);
}

int				check_format_tube(char *line)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (line[i] != '\0')
	{
		i++;
		if (line[i] == '-')
			k++;
	}
	if (k > 2)
		return (-1);
	return (0);
}
