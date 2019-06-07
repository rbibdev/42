/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:36:55 by arbib             #+#    #+#             */
/*   Updated: 2018/08/09 22:29:06 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

/*
****************************************************************************
**********************************Structure*********************************
****************************************************************************
*/
typedef	struct		s_piece
{
	char			**pie;
	int				x_min;
	int				y_min;
	int				x_max;
	int				y_max;
	int				size_x;
	int				size_y;
	int				nb_etoile;
	int				nb_etoile_b;
}					t_piece;

typedef	struct		s_best
{
	int				best_x;
	int				best_y;
}					t_best;

typedef	struct		s_plateau
{
	int				i;
	int				t;
	char			**plat;
	char			**plat_bis;
	int				best_x;
	int				best_y;
	int				size_x;
	int				size_y;
	char			letter;
	char			letter_advers;
	int				y_adv;
	int				x_adv;
	int				x_me;
	int				y_me;
	struct s_piece	*piece;
}					t_plateau;
/*
****************************************************************************
**********************************fonctions*********************************
****************************************************************************
*/
int					main(void);
int					ft_filler_first(t_plateau *pl);
int					ft_filler(t_plateau *pl);
int					ft_abs(int i);
void				ft_get_lettre(t_plateau *pl);
int					ft_get_xy_pl(t_plateau *pl);
int					ft_get_xy_pc(t_plateau *pl);
int					ft_chck_char(char *str);
void				ft_minxy(t_plateau *pl);
int					ft_get_pl(t_plateau *pl);
char				*ft_check_plat(t_plateau *pl);
int					ft_get_pc(t_plateau *pl);
char				*ft_check_piece(t_plateau *pl);
int					ft_get_best(t_plateau *pl);
int					ft_get_me(t_plateau *pl);
int					ft_get_adv(t_plateau *pl);
int					ft_check_pos_2(t_plateau *pl, int i, int j, int t);
int					ft_check_pos(t_plateau *pl, int i, int j);
void				ft_print_res(t_plateau *pl);
int					ft_print_best_choix(t_best *t, int k, t_plateau *pl);
int					ft_print_best(t_best *t, int k, t_plateau *pl);
int					ft_print_best_bis(t_best *t, int k, t_plateau *pl);
void				ft_check_pos_bis(t_plateau *pl, int i, int j);
int					ft_put_piece(t_plateau *pl);
void				ft_free_ta_race(char **tab, int t);
#endif
