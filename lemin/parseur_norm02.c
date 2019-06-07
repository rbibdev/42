/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_norm02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:00:02 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:11:41 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int		is_space(char n, char *str, int i)
{
	if (str[i] == n)
		return (1);
	else
		return (0);
}

int		check_nb_is_valid(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		return (-1);
	return (0);
}

int		number_of_room(char *line, t_cellules *room)
{
	int		i;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (check_nb_is_valid(str) == -1)
		return (-1);
	i = ft_strlen(str[0]);
	if (my_isdigitstr(str[1]) == -1)
		return (-1);
	if (my_isdigitstr(str[2]) == -1)
		return (-1);
	if (!(room->nom))
	{
		if (!(room->nom = ft_memalloc(sizeof(char) * i + 1)))
			exit(1);
	}
	ft_strcpy(room->nom, str[0]);
	ft_free(str, 3);
	return (0);
}

int		check_words(char *line, char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != line[i])
			return (-1);
		i++;
	}
	return (0);
}

int		order_of_lemin(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 's')
		{
			if (check_words(line, "##start", i) == 0)
				return (0);
		}
		else if (line[i] == 'e')
		{
			if (check_words(line, "##end", i) == 0)
				return (1);
		}
		i++;
	}
	return (-1);
}
