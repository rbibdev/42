/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:06:16 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 21:47:01 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ss;
	int		a;

	a = 0;
	if (s != NULL && f != NULL)
	{
		if (!(ss = (ft_memalloc(ft_strlen(s) + 1))))
			return (NULL);
		while (s[a])
		{
			ss[a] = f(s[a]);
			a++;
		}
		ss[a] = '\0';
		return (ss);
	}
	return (NULL);
}
