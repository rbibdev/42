/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:59:58 by arbib             #+#    #+#             */
/*   Updated: 2017/12/19 03:14:25 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_point
{
	int				x[4];
	int				y[4];
	int				x_min;
	int				y_min;
	int				size_x;
	int				size_y;
	char			letter;
	struct s_point	*next;
}					t_tetri;

typedef struct		s_coord
{
	int x;
	int y;
}					t_coord;

t_coord				ft_inc_pos(t_coord pos);
t_tetri				*ft_fill_size(t_tetri *list);
t_tetri				*ft_fill_min(t_tetri *list);
t_tetri				*ft_fill_coord(t_tetri *list, char *buff);
t_tetri				*ft_stock_tetri(int content,
						t_tetri *last, int fd, int *nb);
t_tetri				*ft_create_list(char *buff, char *av, int *nb);
int					ft_check_links(char *buff);
int					ft_check_tetri(char *buff);
char				**ft_create_map(int size_map, char **map);
int					ft_tetri_allowed(char **map, t_tetri *list,
						t_coord pos, int *size_map);
char				**ft_remove_tetri(char **map, t_tetri *list, t_coord pos);
char				**ft_add_tetri(char **map, t_tetri *list, t_coord pos);
int					ft_search_sol(char **map, t_tetri *list, t_coord pos,
						int *size_map);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
void				ft_trait_1st(t_tetri *new, char *buff);

#endif
