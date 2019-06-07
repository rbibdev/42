/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 12:07:55 by arbib             #+#    #+#             */
/*   Updated: 2017/11/20 00:43:39 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}