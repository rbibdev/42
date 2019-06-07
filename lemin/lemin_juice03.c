/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_juice03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:37:02 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:09:13 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

t_chemin				*f_cree_chemin(t_passage *pass, int i)
{
	t_chemin			*chem;

	chem = (t_chemin *)ft_memalloc(sizeof(t_chemin));
	chem->passage = pass;
	chem->longeur = i;
	chem->util = 0;
	chem->next = NULL;
	return (chem);
}

void					new_chemin(t_ressources *ress, t_passage *pass, int i)
{
	t_chemin			*chem;

	if (ress->chemins == NULL)
		ress->chemins = f_cree_chemin(pass, i);
	else
	{
		chem = ress->chemins;
		while (chem->next)
			chem = chem->next;
		chem->next = f_cree_chemin(pass, i);
	}
}

t_passage				*f_cree_passage(t_cellules *cell)
{
	t_passage			*tmp;

	if (!(tmp = (t_passage*)ft_memalloc(sizeof(t_passage))))
		return (NULL);
	tmp->cellule = cell;
	tmp->cellule->util = 0;
	tmp->next = NULL;
	return (tmp);
}

void					add_passage(t_passage *pass, t_ressources *ress)
{
	t_passage			*tmp_pass;
	t_passage			*tmp_pass1;
	int					i;

	if (pass == NULL || ress == NULL)
		return ;
	tmp_pass = NULL;
	tmp_pass1 = NULL;
	i = 0;
	while (pass)
	{
		if (tmp_pass == NULL)
		{
			tmp_pass = f_cree_passage(pass->cellule);
			tmp_pass1 = tmp_pass;
		}
		else
			tmp_pass1->next = f_cree_passage(pass->cellule);
		pass = pass->next;
		if (tmp_pass1->next != NULL)
			tmp_pass1 = tmp_pass1->next;
		i++;
	}
	new_chemin(ress, tmp_pass, i);
}

t_passage				*find_chemin(t_ressources *ress, t_passage *pass,
							t_cellules *cell, t_cellconnect *tmp2)
{
	t_passage			*tmp;

	tmp = pass;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		pass = f_cree_passage(cell);
	else
		tmp->next = f_cree_passage(cell);
	if (!ft_strcmp(cell->nom, ress->fin->nom))
	{
		add_passage(pass, ress);
		return (pass);
	}
	tmp2 = cell->suit;
	while (tmp2)
	{
		if (!check_passage(pass, tmp2->cell))
		{
			find_chemin(ress, pass, tmp2->cell, NULL);
			clear_passage(pass);
		}
		tmp2 = tmp2->next;
	}
	return (pass);
}
