/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:33:42 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 22:49:51 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*ss;
	size_t	t;

	t = ft_strlen(s);
	ss = NULL;
	if (c == '\0')
		return ((char*)&s[t]);
	while (*s)
	{
		cc = *s;
		if (c == cc)
			ss = (char*)s;
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	return (ss);
}
