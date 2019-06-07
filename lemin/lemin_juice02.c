/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_juice02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:33:59 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 20:00:18 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lemin.h"

t_cellconnect			*add_connection(t_cellules *cell)
{
	t_cellconnect		*conn;

	conn = (t_cellconnect *)ft_memalloc(sizeof(t_cellconnect));
	conn->cell = cell;
	conn->next = NULL;
	return (conn);
}

void					f_connect(t_cellules *cell1, t_cellules *cell2)
{
	t_cellconnect		*tmp_cell;

	if (!cell2 && !cell1)
		return ;
	if ((tmp_cell = cell2->suit) == NULL)
	{
		cell2->suit = add_connection(cell1);
		return ;
	}
	while (tmp_cell->next != NULL)
		tmp_cell = tmp_cell->next;
	tmp_cell->next = add_connection(cell1);
}

int						f_cellconnect(t_ressources *ress)
{
	t_tube				*tube_list;

	if ((tube_list = ress->tubes) == NULL)
		return (-1);
	while (tube_list != NULL)
	{
		if (tube_list->cellule_dep != NULL && tube_list->cellule_arr != NULL)
		{
			f_connect(tube_list->cellule_dep, tube_list->cellule_arr);
			f_connect(tube_list->cellule_arr, tube_list->cellule_dep);
		}
		tube_list = tube_list->next;
	}
	return (0);
}

int						check_passage(t_passage *pass, t_cellules *cell)
{
	t_passage			*tmp;

	tmp = pass;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->cellule->nom, cell->nom))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void					clear_passage(t_passage *pass)
{
	t_passage			*tmp;

	tmp = pass;
	if (tmp == NULL)
		return ;
	if (tmp->next == NULL)
	{
		tmp->cellule = NULL;
		free(tmp);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->cellule = NULL;
	free(tmp->next);
	tmp->next = NULL;
}
