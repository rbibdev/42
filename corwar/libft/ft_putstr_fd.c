/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:36:52 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:35:21 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}