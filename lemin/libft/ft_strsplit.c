/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 05:28:55 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 22:28:44 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_str(char *s, char c)
{
	int		check;
	int		nb_str;

	check = 0;
	nb_str = 0;
	while (*s)
	{
		while (*s != c && *s)
		{
			if (check == 0)
			{
				check = 1;
				nb_str++;
			}
			s++;
		}
		while (*s == c && *s)
		{
			check = 0;
			s++;
		}
	}
	return (nb_str);
}

static int	get_nb_char(char *s, int *pos, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[*pos])
	{
		while (s[*pos] != c && s[*pos])
		{
			j++;
			(*pos)++;
		}
		while (s[*pos] == c && s[*pos])
			if (j == 0)
				(*pos)++;
			else
				return (j);
	}
	return (j);
}

static char	*ft_add_str(char *tab, int *pos, int j, char *s)
{
	int		d;
	int		i;

	i = 0;
	d = *pos - j;
	while (i < j)
	{
		tab[i] = s[d];
		i++;
		d++;
	}
	tab[i] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		pos;
	int		mots;

	i = 0;
	if (s == NULL || !c)
		return (NULL);
	mots = get_nb_str((char*)s, c);
	pos = 0;
	count = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (mots + 1))))
		return (NULL);
	while (i < mots)
	{
		count = get_nb_char((char*)s, &pos, c);
		tab[i] = (char*)ft_memalloc(sizeof(char) * (count + 1));
		tab[i] = ft_add_str(tab[i], &pos, count, (char*)s);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
