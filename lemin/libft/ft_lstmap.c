/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:43:10 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 22:41:37 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*last;
	t_list	*tete;

	if (lst == NULL)
		return (NULL);
	if (!(last = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	last = f(lst);
	tete = last;
	lst = lst->next;
	while (lst)
	{
		if (!(list = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		list = f(lst);
		last->next = list;
		last = list;
		lst = lst->next;
	}
	return (tete);
}
