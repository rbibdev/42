/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:38:23 by arbib             #+#    #+#             */
/*   Updated: 2017/11/07 19:38:26 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int			ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		write(1, &str[i++], 1);
	return (0);
}

void		print_file(char *name)
{
	int		fd;
	char	buffer[50];
	int		size;

	if ((fd = open(name, O_RDONLY)) == -1)
		return ;
	while ((size = read(fd, buffer, 49)) > 0)
	{
		buffer[size] = '\0';
		ft_putstr(buffer);
	}
	close(fd);
}

int			main(int ac, char **av)
{
	if (ac == 1)
		return (ft_putstr("File name missing.\n"));
	if (ac == 3)
		return (ft_putstr("Too many arguments.\n"));
	print_file(av[1]);
	return (0);
}
