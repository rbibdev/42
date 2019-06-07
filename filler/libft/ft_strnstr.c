/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:04:27 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 16:58:03 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (to_find[0] == str[i])
		{
			k = 0;
			while (to_find[k] == str[i + k] && (k + i) < len)
			{
				k++;
				if (to_find[k] == '\0')
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}
