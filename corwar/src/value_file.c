/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 06:15:15 by arbib             #+#    #+#             */
/*   Updated: 2019/05/09 10:09:16 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				ft_init_check_para(t_list *tmp, int *type, int *count,
					int *index)
{
	*index = 0;
	*count = 0;
	*type = 0;
	tmp = tmp->next;
	return (1);
}

t_token			*ft_get_token(t_list *tmp)
{
	t_token		*tk;

	tk = NULL;
	if (tmp != NULL)
		tk = ((t_token *)(tmp->content));
	return (tk);
}

int				ft_get_label_val(t_line *tmp, t_line *dir_line, t_line *label)
{
	int			val;

	val = 0;
	if (dir_line->num > label->num)
	{
		while (tmp && tmp != label)
			tmp = tmp->next;
		while (tmp && tmp != dir_line)
		{
			val = val - tmp->byte_len;
			tmp = tmp->next;
		}
	}
	else if (dir_line->num < label->num)
	{
		while (tmp && tmp != dir_line)
			tmp = tmp->next;
		while (tmp && tmp != label)
		{
			val = val + tmp->byte_len;
			tmp = tmp->next;
		}
	}
	return (val);
}

int				ft_get_args_value(t_line *lines, t_line *lsrc, t_token *token)
{
	t_line		*tmp;
	t_line		*tmp1;
	char		*label;

	if (token->type == T_Dir || token->type == T_Reg)
		token->value = ft_atoi(token->content + 1);
	else if (token->type == T_Ind)
		token->value = ft_atoi(token->content);
	else if (token->type == T_DLabel || token->type == T_ILabel)
	{
		label = token->content + (token->type == T_DLabel ? 2 : 1);
		tmp = lines;
		tmp1 = lines;
		while (tmp)
		{
			if (tmp->type == T_Label && !ft_strcmp(tmp->content, label))
			{
				token->value = ft_get_label_val(tmp1, lsrc, tmp);
				return (0);
			}
			tmp = tmp->next;
		}
		return (ft_show_error("Label doesn't exist", 0, -1));
	}
	return (0);
}

int				ft_calc_length_plus(t_list *tmp, t_op *op, t_line *line)
{
	t_token		*tk;

	tk = ft_get_token(tmp);
	if (tk->type == T_Dir && !(op->index))
		line->byte_len += T_DIR_LENGTH;
	if (tk->type == T_DLabel && !(op->index))
		line->byte_len += T_DIR_LENGTH;
	else if ((tk->type == T_DLabel || tk->type == T_Dir) && op->index)
		line->byte_len += T_DLAB_LENGTH;
	else if (tk->type == T_Ind || tk->type == T_ILabel)
		line->byte_len = line->byte_len + T_IND_LENGTH;
	else if (tk->type == T_Reg)
		line->byte_len = line->byte_len + T_REG_LENGTH;
	return (0);
}
