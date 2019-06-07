/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 08:11:09 by arbib             #+#    #+#             */
/*   Updated: 2019/05/07 19:10:38 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

int			ft_get_name(t_root *root, t_line *line, char *str)
{
	int		start;
	int		end;

	start = 5;
	if (!strncmp(str, NAME_CMD_STRING, 5) && ft_strlen(str) <= PROG_NAME_LENGTH)
	{
		while (str && str && ft_isspace(str[start])
				&& str[start] != '"')
			start++;
		end = start + 1;
		while (ft_strlen(str) > 5 && str && str[end] && str[end] != '"')
			end++;
		if (str[end] != '"')
			return (ft_show_error("Name is not in one line", 0, -1));
		ft_strncpy(root->header.prog_name, &str[start + 1],
			end - start - 1);
		while (str && ft_strlen(str) > 5 && str[++end])
		{
			if (!ft_isspace(str[end]))
				return (ft_show_error("Name is in wrong Format", 0, -1));
		}
		line->type = T_Cmd_name;
	}
	return (0);
}

int			ft_get_comment(t_root *root, t_line *line, char *str)
{
	int		start;
	int		end;

	start = 8;
	if (!strncmp(str, COMMENT_CMD_STRING, 8)
		&& ft_strlen(str) <= COMMENT_LENGTH)
	{
		while (str && ft_isspace(str[start])
		&& str[start] != '"')
			start++;
		end = start + 1;
		while (ft_strlen(str) > 8 && str[end] && str[end] != '"')
			end++;
		if (str[end] != '"')
			return (ft_show_error("Comment is not in one line", 0, -1));
		ft_strncpy(root->header.comment, &str[start + 1], end - start - 1);
		while (str && ft_strlen(str) > 8 && str[++end])
		{
			if (!ft_isspace(str[end]))
				return (ft_show_error("Comment is in wrong Format", 0, -1));
		}
		line->type = T_Cmd_comment;
	}
	return (0);
}

int			ft_check_params(t_line *line)
{
	t_list	*tmp;
	int		count;
	int		indx;
	int		type;
	t_token *tk;

	if (!(tmp = line->tokens) || ft_init_check_para(tmp, &type, &count, &indx))
		return (0);
	tk = ft_get_token(tmp);
	if (tk != NULL && tk->type == T_Operation)
		count = tk->op->opcode;
	if (count > 0 && g_op_tab[count - 1].nb_args != line->nb_params)
		return (ft_show_error("Wrong number of args", 0, -1));
	if (!(tmp->next))
		return (ft_show_error("No args for instruction", 0, -1));
	while (tmp || indx < g_op_tab[count - 1].nb_args)
	{
		tk = ft_get_token(tmp);
		type = (tk->type == T_DLabel ? 2 : tk->type - 8);
		type = (type == T_ILabel - 8 ? 4 : type);
		if (type & ~g_op_tab[count - 1].args[indx++])
			return (ft_show_error("Wrong type of parameteres", 0, -1));
		tmp = tmp->next;
	}
	return (0);
}

int			ft_calc_length(t_line *line, t_root *root)
{
	t_list	*tmp;
	t_op	*op;
	t_token *tk;

	if (!(tmp = line->tokens))
		return (-1);
	tk = ft_get_token(tmp);
	op = tk->op;
	line->byte_len = 1;
	if (tk->type == T_Cmd_comment || tk->type == T_Cmd_name)
		return (0);
	if (op && op->octal_code)
		(line->byte_len)++;
	while (tmp && op)
	{
		ft_calc_length_plus(tmp, op, line);
		tmp = tmp->next;
	}
	root->header.prog_size += line->byte_len;
	return (0);
}

int			ft_parse_file(t_root *root)
{
	t_line	*tmp;

	tmp = root->lines;
	while (tmp)
	{
		if (ft_check_comment(tmp) == 0)
		{
			if (tmp->type == T_Unknown)
				tmp->type = T_Exec;
			if (!root->header.prog_name[0])
				ft_get_name(root, tmp, tmp->content);
			if (!root->header.comment[0])
				ft_get_comment(root, tmp, tmp->content);
			if ((tmp->type == T_Exec) && (ft_token_file(tmp) == -1
				|| ft_check_params(tmp) == -1))
				return (ft_show_error("Can't initiate line", tmp->num, -1));
			if (tmp->type == T_Label)
				tmp->content[ft_strlen(tmp->content) - 1] = '\0';
			if (tmp->type == T_Exec)
				ft_calc_length(tmp, root);
		}
		tmp = tmp->next;
	}
	return (0);
}
