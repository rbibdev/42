/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 06:05:16 by arbib             #+#    #+#             */
/*   Updated: 2019/05/07 19:17:02 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

int				get_operation(t_token *token)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(token->content, (g_op_tab[i]).name) == 0)
		{
			if (!(token->op = (t_op *)malloc(sizeof(t_op))))
				return (-1);
			ft_memcpy(token->op, &(g_op_tab[i]), sizeof(t_op));
		}
		i++;
	}
	return (0);
}

int				ft_check_oper(char *oper)
{
	int			i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(g_op_tab[i].name, oper) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				ft_isregister(char *str)
{
	if (!str[0] && str[0] != REGISTER_CHAR)
		return (-1);
	if (str[1] && (ft_atoi(str + 1) > REG_NUMBER || ft_atoi(str + 1) < 1))
		return (-1);
	return (0);
}

int				ft_check_comment(t_line *l)
{
	int			i;

	i = 0;
	while (l->content && l->content[i] && ft_isspace(l->content[i]))
		i++;
	if (l->content[i] == COMMENT_CHAR)
	{
		return (1);
	}
	return (0);
}

int				is_label_char(char c)
{
	int			i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}
