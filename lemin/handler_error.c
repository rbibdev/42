/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:52:37 by macuguen          #+#    #+#             */
/*   Updated: 2018/10/26 20:10:21 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int		handler_error(t_ressources *ress)
{
	if (ress->error == 1)
		ft_putstr("Error 1 : bag argument for your ants.");
	else if (ress->error == 2)
	{
		ft_putstr("Error 2 : you must enter 3 arguments, the coordinates");
		ft_putstr("must be written in digits.\nEx: room 9 5\n");
	}
	else if (ress->error == 3)
		ft_putstr("Error 3 : choose different room names.");
	else if (ress->error == 4)
		ft_putstr("Error 4 : Bad format tube.");
	else if (ress->error == 5 || ress->error == 6)
		ft_putstr("Error 5 : Bad Format");
	return (0);
}
