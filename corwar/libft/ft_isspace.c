/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 06:09:15 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:34:32 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_isspace(int c)
{
	if (c == ' ' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int				ft_is_whitespace(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		++i;
	}
	return (1);
}
