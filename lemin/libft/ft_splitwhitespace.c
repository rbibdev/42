/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:45:29 by arbib             #+#    #+#             */
/*   Updated: 2018/08/05 03:32:02 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_nb_str(char *str)
{
	int nb;
	int status;

	nb = 0;
	status = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t')
		{
			status = 0;
			str++;
		}
		while (*str >= 33 && *str <= 126)
		{
			if (status == 0)
			{
				status = 1;
				nb++;
			}
			str++;
		}
	}
	return (nb);
}

int			ft_nb_char(char *str, int *pos)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[*pos])
	{
		while (str[*pos] >= 33 && str[*pos] <= 126)
		{
			j++;
			(*pos)++;
		}
		while (str[*pos] == ' ' || str[*pos] == '\n'
		|| str[*pos] == '\t' || str[*pos] == '\0')
			if (j == 0)
				(*pos)++;
			else
				return (j);
	}
	return (j + 1);
}

char		*ft_char_malloc(char *tab, int *pos, int j, char *str)
{
	int		d;
	int		i;

	i = 0;
	d = *pos - j;
	while (i < j)
	{
		tab[i] = str[d];
		i++;
		d++;
	}
	tab[i] = '\0';
	return (tab);
}

char		**ft_splitwhitespace(char *str)
{
	char	**tab;
	int		i;
	int		count;
	int		pos;
	int		mots;

	i = 0;
	mots = ft_nb_str(str);
	pos = 0;
	count = 0;
	tab = (char**)malloc(sizeof(char*) * (mots + 1));
	while (i < mots)
	{
		count = ft_nb_char(str, &pos);
		tab[i] = (char*)malloc(sizeof(char) * (count + 1));
		tab[i] = ft_char_malloc(tab[i], &pos, count, str);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
