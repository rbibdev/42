/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:46:09 by arbib             #+#    #+#             */
/*   Updated: 2017/11/16 04:01:21 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (n > 0 && src[j] != '\0')
	{
		dest[i + j] = (char)src[j];
		n--;
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
