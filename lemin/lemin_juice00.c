/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_juice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:31:27 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:06:40 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"
#include "stdio.h"

void					inverser_pass(t_chemin *p1, t_chemin *p2)
{
	t_passage			*pass_tmp;
	int					i;

	pass_tmp = p1->passage;
	i = p1->longeur;
	p1->passage = p2->passage;
	p1->longeur = p2->longeur;
	p2->passage = pass_tmp;
	p2->longeur = i;
}

int						trie_chemin(t_ressources *ress)
{
	t_chemin			*tmp;
	int					j_chem;
	int					i;

	j_chem = 0;
	i = 0;
	if (!ress->chemins || !ress->chemins->next)
		return (0);
	tmp = ress->chemins;
	while (tmp && ++j_chem > 0)
		tmp = tmp->next;
	while (++i < j_chem)
	{
		tmp = ress->chemins;
		while (tmp && tmp->next)
		{
			if (tmp->longeur > tmp->next->longeur)
				inverser_pass(tmp, tmp->next);
			tmp = tmp->next;
		}
	}
	return (0);
}

int						lemin_juice(t_ressources *ress)
{
	t_passage *passa;

	passa = NULL;
	if (!ress->debut || !ress->fin || f_cellconnect(ress) == -1)
		return (-1);
	passa = find_chemin(ress, NULL, ress->debut, NULL);
	free(passa);
	if (ress->chemins == NULL)
		return (-1);
	if (trie_chemin(ress) == -1)
		return (-1);
	return (0);
}

int						main(int ac, char **av)
{
	int					max;
	t_ressources		ress;

	max = 0;
	ft_bzero(&ress, sizeof(t_ressources));
	if (parse_map(&ress, ac, av) != 0)
	{
		handler_error(&ress);
		ft_putstr("\n");
		ft_putstr(ress.map);
		ft_putstr("\n");
		free(ress.map);
		return (-1);
	}
	ft_putstr(ress.map);
	ft_putstr("\n");
	max = lemin_juice(&ress);
	if (ress.chemins != NULL)
		ft_en_marche(&ress);
	else
		ft_putstr("\nError 407 : No Way Found \n");
	free(ress.map);
	return (0);
}
