/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:03:28 by arbib             #+#    #+#             */
/*   Updated: 2018/08/08 22:41:03 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int			main(int c, char **v)
{
	int		fd;
	int		i;
	char	*line;
	int		j;

	i = 1;
	while (i < c)
	{
		if ((fd = open(v[i], O_RDONLY)) != -1)
		{
			j = 1;
			while (j == 1)
			{
				j = get_next_line(fd, &line);
				printf("%s\n", line);
				free(line);
			}
			close(fd);
			i++;
		}
	}
}
