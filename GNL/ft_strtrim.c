/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:09:26 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 22:30:17 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*c;
	int				i;
	unsigned int	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = (int)ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i--;
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j++;
	}
	if (i < 0)
	{
		j = 0;
	}
	if (!(c = (ft_memalloc(i - j + 2))))
		return (NULL);
	c = ft_strsub(s, j, (i - j + 1));
	c[i - j + 1] = '\0';
	return (c);
}
