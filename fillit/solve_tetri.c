/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimet <agimet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:37:13 by agimet            #+#    #+#             */
/*   Updated: 2017/12/18 12:13:30 by agimet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size_map, char **map)
{
	int i;
	int j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size_map + 1)))
		return (NULL);
	map[size_map + 1] = 0;
	while (i < size_map)
	{
		j = 0;
		if (!(map[i] = (char*)malloc(sizeof(char) * size_map + 1)))
			return (NULL);
		map[i][size_map + 1] = '\0';
		while (j < size_map)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		ft_tetri_allowed(char **map, t_tetri *list, t_coord pos, int *size_map)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (((pos.x + list->x[count]) < *size_map) &&
			((pos.y + list->y[count]) < *size_map))
		{
			if (map[pos.x + list->x[count]][pos.y + list->y[count]] == '.')
			{
				count++;
				if (count == 4)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char	**ft_remove_tetri(char **map, t_tetri *list, t_coord pos)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (count < 4)
	{
		map[pos.x + list->x[count]][pos.y + list->y[count]] = '.';
		count++;
	}
	return (map);
}

char	**ft_add_tetri(char **map, t_tetri *list, t_coord pos)
{
	int count;

	count = 0;
	while (count < 4)
	{
		map[pos.x + list->x[count]][pos.y + list->y[count]] = list->letter;
		count++;
	}
	return (map);
}

int		ft_search_sol(char **map, t_tetri *list, t_coord pos, int *size_map)
{
	if (!list)
		return (1);
	while (pos.y < *size_map)
	{
		pos.x = 0;
		while (pos.x < *size_map)
		{
			if (ft_tetri_allowed(map, list, pos, size_map) == 1)
			{
				ft_add_tetri(map, list, pos);
				if (ft_search_sol(map, list->next,
					ft_inc_pos(pos), size_map) == 1)
					return (1);
				else
					ft_remove_tetri(map, list, pos);
			}
			pos.x = pos.x + 1;
		}
		pos.y = pos.y + 1;
	}
	return (0);
}
