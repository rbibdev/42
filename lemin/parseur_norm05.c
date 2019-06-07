/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:04:14 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 15:14:33 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int		parse_map(t_ressources *map, int ac, char **av)
{
	char	*line;

	line = NULL;
	init_var_s(map);
	who_fd(map->hm, ac, av);
	map->error = 0;
	while (get_next_line(map->hm->fd, &line) == 1)
	{
		if (check_line(line) == 0)
		{
			if (parseur(line, map) == -1)
			{
				copy_line_in_map(map, line);
				return (-1);
			}
			copy_line_in_map(map, line);
		}
		free(line);
	}
	free(line);
	free(map->hm);
	return (0);
}

void	print_chemin(int num, char *nom)
{
	ft_putstr("L");
	ft_putnbr(num);
	ft_putstr("-");
	ft_putstr(nom);
	ft_putstr(" ");
}
