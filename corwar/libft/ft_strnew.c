/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:07:00 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:35:44 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*c;

	if ((c = ft_memalloc(size + 1)))
	{
		while (size > 0)
		{
			c[size] = '\0';
			size--;
		}
		return (c);
	}
	else
		return (NULL);
}
