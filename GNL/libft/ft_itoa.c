/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:27:37 by arbib             #+#    #+#             */
/*   Updated: 2017/11/19 20:26:54 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	char			*ss;
	int				a;
	unsigned int	nn;
	unsigned int	tt;

	nn = n;
	a = 0;
	if (n < 0)
	{
		a++;
		nn = -n;
	}
	tt = nn;
	while (tt /= 10)
		a++;
	if (!(ss = (ft_memalloc((size_t)(a + 2)))))
		return (NULL);
	ss[a + 1] = '\0';
	ss[a] = (nn % 10) + '0';
	while (nn /= 10)
		ss[--a] = (nn % 10) + '0';
	if (n < 0)
		ss[0] = '-';
	return (ss);
}
