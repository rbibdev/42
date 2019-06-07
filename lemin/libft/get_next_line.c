/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:32:18 by arbib             #+#    #+#             */
/*   Updated: 2018/03/16 13:32:20 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_len(const char *s)
{
	int				i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str;
	char			*tmp1;
	int				taille;

	(str == NULL) ? str = ft_strnew(BUFF_SIZE) : 0;
	while ((taille = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[taille] = '\0';
		tmp1 = ft_strjoin(str, buff);
		ft_memdel((void**)&str);
		str = tmp1;
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	if (fd < 0 || taille == -1)
		return (-1);
	*line = ft_strsub(str, 0, ft_len(str));
	if (taille == 0 && str[0] == '\0')
		return (0);
	tmp1 = ft_strsub(str, ft_len(str) + 1, (ft_strlen(str) - ft_len(str)));
	ft_memdel((void**)&str);
	str = tmp1;
	return (1);
}
