/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimet <agimet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:37:48 by agimet            #+#    #+#             */
/*   Updated: 2017/12/19 04:15:35 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display_map(char **map, int size_map)
{
	int i;
	int ac;

	i = 0;
	ac = 0;
	while (i < size_map)
	{
		ac = 0;
		while (ac < (size_map))
		{
			ft_putchar(map[ac][i]);
			ac++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_treatment(int nb, t_tetri *list)
{
	int		size_map;
	char	**map;
	t_coord	pos;

	pos.x = 0;
	pos.y = 0;
	size_map = 0;
	map = NULL;
	while (size_map * size_map < nb * 4)
		size_map++;
	map = ft_create_map(size_map, map);
	while (ft_search_sol(map, list, pos, &size_map) == 0)
	{
		pos.x = 0;
		pos.y = 0;
		size_map = size_map + 1;
		map = ft_create_map((size_map), map);
	}
	ft_display_map(map, size_map);
}

int		main(int ac, char **av)
{
	char	*buff;
	t_tetri	*list;
	int		nb;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sourcefile [un seule ficher a la fois] \n");
		return (0);
	}
	nb = 0;
	if (!(list = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	if (!(buff = (char*)malloc(sizeof(char) * 21)))
		return (0);
	list = ft_create_list(buff, av[1], &nb);
	if (list == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_treatment(nb, list);
	return (0);
}
