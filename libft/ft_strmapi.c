/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:48:35 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 21:58:28 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ss[a] = f(a, s[a]);
			a++;
		}
		ss[a] = '\0';
		return (ss);
	}
	return (NULL);
}
