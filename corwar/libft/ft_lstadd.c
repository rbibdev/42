/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:25:44 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:34:38 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	new->next = (*alst);
	*alst = new;
}

void		ft_lstadd_back(t_list **old, t_list *new)
{
	t_list	*tmp;

	if (!old)
		return ;
	else if (!(*old))
		*old = new;
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
