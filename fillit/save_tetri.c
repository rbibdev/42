/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimet <agimet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:37:25 by agimet            #+#    #+#             */
/*   Updated: 2017/12/19 04:14:54 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_fill_size(t_tetri *list)
{
	int count;
	int x_max;
	int y_max;

	count = 0;
	x_max = 0;
	y_max = 0;
	while (count < 4)
	{
		if (list->x[count] > x_max)
			x_max = list->x[count];
		if (list->y[count] > y_max)
			y_max = list->y[count];
		count++;
	}
	list->size_x = x_max - list->x_min + 1;
	list->size_y = y_max - list->y_min + 1;
	count = 0;
	while (count < 4)
	{
		list->x[count] = list->x[count] - list->x_min;
		list->y[count] = list->y[count] - list->y_min;
		count++;
	}
	return (list);
}

t_tetri		*ft_fill_min(t_tetri *list)
{
	int x_min;
	int y_min;
	int count;

	count = 1;
	x_min = list->x[0];
	y_min = list->y[0];
	while (count < 4)
	{
		if (x_min > list->x[count])
			x_min = list->x[count];
		if (y_min > list->y[count])
			y_min = list->y[count];
		count++;
	}
	count = 0;
	list->x_min = x_min;
	list->y_min = y_min;
	return (list);
}

t_tetri		*ft_fill_coord(t_tetri *list, char *buff)
{
	int i;
	int x;
	int y;
	int count;

	i = 0;
	x = 0;
	y = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && !(x = 0) && (y += 1))
			i++;
		if (buff[i] == '#')
		{
			list->x[count] = x;
			list->y[count] = y;
			count++;
		}
		x++;
		i++;
	}
	return (list);
}

t_tetri		*ft_stock_tetri(int content,
				t_tetri *last, int fd, int *nb)
{
	t_tetri	*new;
	char	c;
	char	buff[21];

	c = 65;
	while (((content = read(fd, buff, 21))) && c++ != 'Z')
	{
		buff[content] = '\0';
		if (ft_check_tetri(buff) == 0)
			return (NULL);
		if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
			return (NULL);
		new = ft_fill_coord(new, buff);
		new = ft_fill_min(new);
		new = ft_fill_size(new);
		new->letter = c;
		last->next = new;
		last = new;
		(*nb)++;
	}
	if (close(fd) == -1)
		return (NULL);
	if (ft_strlen(buff) == 21)
		return (NULL);
	return (last);
}

t_tetri		*ft_create_list(char *buff, char *av, int *nb)
{
	t_tetri *last;
	t_tetri *new;
	t_tetri *first;
	int		fd;
	int		content;

	last = NULL;
	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	if ((content = read(fd, buff, 21)))
	{
		buff[content] = '\0';
		if (ft_check_tetri(buff) == 0)
			return (NULL);
		ft_trait_1st(new, buff);
		first = new;
		last = new;
		*nb = 1;
	}
	last = ft_stock_tetri(content, last, fd, nb);
	if ((last == NULL) || ((ft_strlen(buff) == 21 && *nb == 1)))
		first = NULL;
	return (first);
}
