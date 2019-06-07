/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:32:53 by arbib             #+#    #+#             */
/*   Updated: 2017/11/17 02:31:16 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	char		cc;
	const char	*ss;

	cc = (char)c;
	ss = s;
	while (*ss != cc)
	{
		if (*ss == '\0')
			return (NULL);
		ss++;
	}
	return ((char*)ss);
}
