/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:10:11 by arbib             #+#    #+#             */
/*   Updated: 2019/05/09 10:08:29 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				ft_trans_tk_val(int value, char *bytecode, int size, int *i)
{
	size_t		j;

	j = 0;
	if (size == 1)
		bytecode[j] = ((size_t)value) % 256;
	else if (size == 2)
	{
		bytecode[j] = ((size_t)value) / 256;
		bytecode[j + 1] = ((size_t)value) % 256;
	}
	else if (size == 4)
	{
		bytecode[j] = ((size_t)value) / (256 * 256 * 256);
		bytecode[j + 1] = (((size_t)value) - bytecode[j] * 256 * 256 * 256)
			/ (256 * 256);
		bytecode[j + 2] = (((size_t)value) - bytecode[j + 1] * 256 * 256) / 256;
		bytecode[j + 3] = (((size_t)value) - bytecode[j + 2] * 256) % 256;
	}
	*i += size;
	return (0);
}

int				ft_translation(t_root *root, t_line *line, t_op *op)
{
	t_token		*tk;
	t_list		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = line->tokens->next;
	while (tmp)
	{
		tk = ft_get_token(tmp);
		j = op->octal_code + i + 1;
		if (ft_get_args_value(root->lines, line, tk))
			return (-1);
		if (tk->type == T_Reg)
			ft_trans_tk_val(tk->value, &(line->bytecode)[j], T_REG_LENGTH, &i);
		else if (tk->type == T_Ind || tk->type == T_ILabel)
			ft_trans_tk_val(tk->value, &(line->bytecode[j]), T_IND_LENGTH, &i);
		else if ((tk->type == T_DLabel || tk->type == T_Dir) && op->index)
			ft_trans_tk_val(tk->value, &(line->bytecode)[j], T_DLAB_LENGTH, &i);
		else if (tk->type == T_Dir || (tk->type == T_DLabel && !op->index))
			ft_trans_tk_val(tk->value, &(line->bytecode)[j], T_DIR_LENGTH, &i);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_get_ope_code(t_list *token, char *byte)
{
	t_list		*tmp;
	t_token		*tk;
	uint8_t		ope_code;
	int			i;

	ope_code = 0;
	i = 0;
	tmp = token;
	while (tmp)
	{
		tk = ft_get_token(tmp);
		if (tk->type == T_DLabel || tk->type == T_Dir
			|| tk->type == T_ILabel || tk->type == T_Ind)
			ope_code |= (1 << (7 - i));
		if (tk->type == T_Reg || tk->type == T_ILabel || tk->type == T_Ind)
			ope_code |= (1 << (6 - i));
		tmp = tmp->next;
		i += 2;
	}
	byte[1] = ope_code;
	return (0);
}

t_op			*ft_get_operation_2(t_line *line)
{
	t_token		*token;
	t_op		*op;

	token = (t_token *)line->tokens->content;
	if (!(op = token->op))
		return (NULL);
	if (op->octal_code)
		ft_get_ope_code(line->tokens->next, line->bytecode);
	line->bytecode[0] = op->opcode;
	return (op);
}

int				ft_convertion_file(t_root *root)
{
	t_line		*tmp;
	t_op		*op;

	tmp = root->lines;
	while (tmp)
	{
		if (tmp->type == T_Exec && tmp->tokens)
		{
			if (!(op = ft_get_operation_2(tmp)))
				return (ft_show_error("Can't get operation", 0, -1));
			if (tmp->tokens->next == NULL)
				return (ft_show_error("No Tokens found", 0, -1));
			if (ft_translation(root, tmp, op) == -1)
				return (ft_show_error("Can't translate line", tmp->num, -1));
		}
		tmp = tmp->next;
	}
	return (0);
}
