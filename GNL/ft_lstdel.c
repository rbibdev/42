/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:02:30 by arbib             #+#    #+#             */
/*   Updated: 2017/11/21 18:24:10 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*m;
	t_list	*nextm;

	m = *alst;
	while (m)
	{
		nextm = m->next;
		del(m->content, m->content_size);
		free(m);
		m = nextm;
	}
	*alst = NULL;
}
