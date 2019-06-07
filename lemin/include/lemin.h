/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 02:00:45 by arbib             #+#    #+#             */
/*   Updated: 2018/10/26 19:50:28 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

/*
****************************************************************************
**********************************Structure*********************************
****************************************************************************
*/
typedef struct				s_home
{
	int						i;
	int						start;
	int						end;
	int						j;
	int						fd;
}							t_home;

typedef struct s_cellconn	t_cellconnect;

typedef struct				s_cellules
{
	char					*nom;
	int						util;
	int						pos_x;
	int						pos_y;
	t_cellconnect			*suit;
	struct s_cellules		*next;
}							t_cellules;

typedef struct				s_cellconn
{
	t_cellules				*cell;
	struct s_cellconn		*next;
}							t_cellconn;

typedef struct				s_passage
{
	t_cellules				*cellule;
	struct s_passage		*next;
}							t_passage;

typedef struct				s_chemin
{
	t_passage				*passage;
	int						longeur;
	int						util;
	struct s_chemin			*next;
}							t_chemin;

typedef struct				s_tube
{
	t_cellules				*cellule_dep;
	t_cellules				*cellule_arr;
	struct s_tube			*next;
}							t_tube;

typedef struct				s_fourm
{
	int						num;
	t_chemin				*chemin_actu;
	t_passage				*pass_actu;
	struct s_fourm			*next;
}							t_fourm;

typedef struct				s_ressources
{
	int						nb_fourm;
	int						error;
	t_fourm					*fourm;
	t_cellules				*cellules;
	t_tube					*tubes;
	t_cellules				*debut;
	t_cellules				*fin;
	t_chemin				*chemins;
	t_chemin				*chemin_final;
	char					*map;
	struct s_home			*hm;
}							t_ressources;
/*
****************************************************************************
**********************************fonctions*********************************
****************************************************************************
*/
int							f_cellconnect(t_ressources *ress);
void						ft_free(char **tab, int t);
int							my_isdigit(int c);
int							my_isdigitstr(char *str);
int							number_of_ants(char *str, t_ressources *map);
t_passage					*find_chemin(t_ressources *ress, t_passage *pass,
								t_cellules *cell, t_cellconnect *tmp2);
int							parse_map(t_ressources *map, int ac, char **av);
void						ft_en_marche(t_ressources *ress);
int							check_passage(t_passage *pass, t_cellules *cell);
void						clear_passage(t_passage *pass);
int							handler_error(t_ressources *ress);
int							check_name_of_room(t_cellules *room, t_cellules
								*begin);
void						copy_line_in_map(t_ressources *map, char *line);
t_cellules					*add_room(t_cellules *room);
int							search_char(char n, char *line);
t_tube						*add_links(t_ressources *map, char **str);
int							check_format_tube(char *line);
int							is_space(char n, char *str, int i);
int							check_nb_is_valid(char **str);
int							number_of_room(char *line, t_cellules *room);
int							check_words(char *line, char *str, int i);
int							order_of_lemin(char *line);
int							room_link(t_ressources *map, char *line);
void						innit_var(t_home *home);
void						who_fd(t_home *home, int ac, char **av);
int							part_tow(t_cellules *room, t_ressources *map);
int							create_room(t_cellules *room, t_cellules *begin,
								char *line, t_ressources *map);
int							part_one(t_cellules *room, t_cellules *begin,
								char *line, t_ressources *map);
void						choice_of_command_start_or_and(char *line,
								t_ressources *map);
int							parseur(char *line, t_ressources *map);
int							check_line(char *line);
void						init_var_s(t_ressources *map);
void						print_chemin(int num, char *nom);

#endif
