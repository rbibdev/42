/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:38:25 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:34:55 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_memdel(void **ap)
{
	char	**c;

	if (ap != NULL)
	{
		c = (char**)ap;
		free(*c);
		*c = NULL;
	}
}