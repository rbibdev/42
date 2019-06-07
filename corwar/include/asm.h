/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:29:53 by arbib             #+#    #+#             */
/*   Updated: 2019/05/07 18:53:15 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "op.h"

# define T_REG_LENGTH	1
# define T_DLAB_LENGTH	2
# define T_IND_LENGTH	2
# define T_DIR_LENGTH	4

typedef enum			e_types
{
	T_Unknown = 0,
	T_Cmd_name,
	T_Cmd_comment,
	T_Comment,
	T_String,
	T_Exec,
	T_Operation,
	T_Label,
	T_DLabel,
	T_Reg,
	T_Dir,
	T_ILabel,
	T_Ind,
}						t_types;

typedef struct			s_token
{
	int					id;
	t_op				*op;
	char				*content;
	t_types				type;
	int					value;
	int					pos_col;
	int					pos_line;
}						t_token;

typedef struct			s_line
{
	int					num;
	t_list				*tokens;
	char				*content;
	int					nb_params;
	char				bytecode[14];
	int					byte_len;
	char				pcode;
	t_types				type;
	struct s_line		*next;
}						t_line;

typedef struct			s_root
{
	t_header			header;
	t_line				*lines;
	char				*in_file;
	char				*out_file;
	int					nb_lines;
	int					fd_in;
	int					fd_out;
	int					i;
}						t_root;

int						ft_check_read(t_root *root);
int						ft_parse_file(t_root *root);
int						ft_token_file(t_line *line);
int						ft_convertion_file(t_root *root);
int						ft_write_champ(t_root *root);
int						ft_finish_it(t_root *root);
int						ft_show_error(char *msg, int ligne, int err);
int						ft_isregister(char *word);
int						get_operation(t_token *token);
int						ft_check_oper(char *oper);
int						ft_check_comment(t_line *l);
int						is_label_char(char c);
t_token					*ft_get_token(t_list *tmp);
int						ft_trans_tk_val(int value, char *bytecode,
							int size, int *i);
int						ft_get_args_value(t_line *lines,
							t_line *lsrc, t_token *token);
int						ft_calc_length_plus(t_list *tmp, t_op *op,
							t_line *line);
int						ft_init_check_para(t_list *tmp, int *type,
							int *count, int *index);
#endif
