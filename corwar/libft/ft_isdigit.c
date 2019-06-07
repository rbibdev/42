/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:43:33 by arbib             #+#    #+#             */
/*   Updated: 2019/04/26 04:21:02 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isdigit(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int					ft_isdigits(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(str))
		return (0);
	return (1);
}
