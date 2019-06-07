/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimet <agimet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:38:02 by agimet            #+#    #+#             */
/*   Updated: 2017/12/19 04:11:06 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_links(char *buff)
{
	int i;
	int test;

	i = 0;
	test = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (i + 1 < 19 && buff[i + 1] == '#')
				test++;
			if (i + 5 < 19 && buff[i + 5] == '#')
				test++;
			if (i - 1 >= 0 && buff[i - 1] == '#')
				test++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				test++;
		}
		i++;
	}
	return (test);
}

int		ft_check_tetri(char *buff)
{
	int i;
	int bloc;
	int point;
	int test;

	test = 0;
	i = 0;
	bloc = 0;
	point = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			bloc++;
		else if (buff[i] == '.')
			point++;
		i++;
	}
	if (point == 12 && bloc == 4)
		test = ft_check_links(buff);
	if (test == 6 || test == 8)
		return (1);
	else
		return (0);
}
