/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:40:18 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 15:34:33 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ds;
	char		*sr;

	ds = (char*)dest;
	sr = (char*)src;
	if (sr < ds)
	{
		while (n--)
			ds[n] = sr[n];
	}
	else
		ft_memcpy(ds, sr, n);
	return (ds);
}
