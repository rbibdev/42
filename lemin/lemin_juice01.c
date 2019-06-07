/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:51:05 by dlaurent          #+#    #+#             */
/*   Updated: 2018/10/26 20:02:13 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

int						get_nb_fourm_t(t_chemin *chem, t_chemin *chem_actu)
{
	int					i;
	int					j;

	i = chem_actu->longeur - 1;
	j = 0;
	while (chem != chem_actu)
	{
		j += (i - (chem->longeur - 2));
		chem = chem->next;
	}
	return (j);
}

int						choix_chemin(t_fourm *fourm, t_ressources *ress)
{
	t_chemin			*chem;
	t_cellules			*cell;
	int					fourm_rest;

	ress->fin->util = 0;
	fourm_rest = ress->nb_fourm - fourm->num + 1;
	chem = ress->chemins;
	while (chem)
	{
		if (chem->passage->next->cellule->util == 0)
			break ;
		chem = chem->next;
	}
	if (chem == NULL)
		return (0);
	if (fourm_rest <= get_nb_fourm_t(ress->chemins, chem))
		return (0);
	cell = chem->passage->next->cellule;
	fourm->chemin_actu = chem;
	fourm->pass_actu = chem->passage->next;
	cell->util = 1;
	chem->util = 1;
	print_chemin(fourm->num, fourm->pass_actu->cellule->nom);
	return (1);
}

int						avance_fourm(t_ressources *ress, t_fourm *fourm,
							t_fourm *fr)
{
	t_fourm				*tmp;
	int					i;

	i = 0;
	tmp = fourm;
	ft_putstr("\n");
	while (tmp != fr)
	{
		if (tmp->pass_actu->next && tmp->pass_actu->next->cellule->util == 0)
		{
			tmp->pass_actu->cellule->util = 0;
			tmp->pass_actu->next->cellule->util = 1;
			tmp->pass_actu = tmp->pass_actu->next;
			i = 1;
			print_chemin(tmp->num, tmp->pass_actu->cellule->nom);
			ress->fin->util = 0;
		}
		else if (tmp->pass_actu->next &&
				tmp->pass_actu->next->cellule->util == 1)
			tmp->pass_actu->cellule->util = 0;
		tmp->chemin_actu->passage->next->cellule->util = 0;
		tmp = tmp->next;
	}
	return (i);
}

t_fourm					*add_fourm(int i)
{
	t_fourm				*fr;

	fr = ft_memalloc(sizeof(t_fourm));
	fr->num = i;
	fr->next = NULL;
	fr->chemin_actu = NULL;
	return (fr);
}

void					ft_en_marche(t_ressources *ress)
{
	int					i;
	t_fourm				*tmp;

	i = 1;
	while (i <= ress->nb_fourm)
	{
		if (ress->fourm == NULL)
		{
			tmp = add_fourm(i);
			ress->fourm = tmp;
		}
		else
		{
			tmp->next = add_fourm(i);
			tmp = tmp->next;
		}
		if (choix_chemin(tmp, ress) == 0)
		{
			avance_fourm(ress, ress->fourm, tmp);
			choix_chemin(tmp, ress);
		}
		i++;
	}
	while (avance_fourm(ress, ress->fourm, NULL))
		;
}
