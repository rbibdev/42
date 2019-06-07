/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:28:58 by arbib             #+#    #+#             */
/*   Updated: 2019/05/09 10:10:22 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

int				ft_token_type(t_token *token)
{
	if (ft_strlen(token->content) == 0)
		return (ft_show_error("Token content is void", 0, -1));
	if (token->content[ft_strlen(token->content) - 1] == LABEL_CHAR)
		token->type = T_Label;
	else if (ft_check_oper(token->content) == 1)
		token->type = T_Operation;
	else if (token->content[0] == DIRECT_CHAR)
	{
		if (token->content[1] == LABEL_CHAR)
		{
			token->type = T_DLabel;
		}
		else if (ft_isdigits(&(token->content[1])))
			token->type = T_Dir;
	}
	else if (token->content[0] == REGISTER_CHAR)
		token->type = T_Reg;
	else if (token->content[0] == LABEL_CHAR)
		token->type = T_ILabel;
	else if (ft_isdigits(token->content))
		token->type = T_Ind;
	else
		return (ft_show_error("Token type doesn't exist", 0, -1));
	return (0);
}

int				ft_check_token(t_token *token)
{
	size_t		i;

	i = 0;
	if (token->type == T_Reg && ft_isregister(token->content) == -1)
		return (ft_show_error("Register error", 0, -1));
	while (token->content[i])
	{
		if (token->type == T_ILabel || token->type == T_DLabel)
		{
			if (!(i == 0 && token->content[i] == DIRECT_CHAR) && !((i == 0 || i == 1) && token->content[i] == LABEL_CHAR) && !ft_strchr(LABEL_CHARS, token->content[i]))
				return (ft_show_error("Label name error", 0, -1));
		}
		else if (token->type == T_Label)
		{
			if (!ft_strchr(LABEL_CHARS, token->content[i])
				&& !(i == ft_strlen(token->content) - 1 &&
				token->content[i] == LABEL_CHAR))
				return (-1);
		}
		i++;
	}
	return (0);
}

int				ft_token_err(t_token *tok)
{
	free(tok->content);
	free(tok);
	return (-1);
}

int				ft_add_token(t_line *line, int start, int end, int id_token)
{
	t_token		*tok;

	if (!(tok = (t_token *)ft_memalloc(sizeof(t_token))))
		return (-1);
	if (!(tok->content = (char *)ft_memalloc(sizeof(char) * (end - start + 1))))
		return (-1);
	tok->id = id_token;
	ft_strncpy(tok->content, &line->content[start], end - start);
	tok->op = NULL;
	tok->type = T_Unknown;
	tok->pos_line = line->num;
	tok->pos_col = start;
	if (ft_token_type(tok) == -1)
		return (ft_token_err(tok));
	if (ft_check_token(tok) == -1)
	{
		ft_show_error("Token content incompatible", 0, -1);
		return (ft_token_err(tok));
	}
	if (tok->type == T_Operation && get_operation(tok) == -1)
		return (ft_token_err(tok));
	ft_lstadd_back(&(line->tokens), ft_lstnew((void *)tok, sizeof(t_token)));
	free(tok);
	return (0);
}

int				ft_token_file(t_line *line)
{
	int			start;
	int			end;
	int			tok_count;

	tok_count = 0;
	start = 0;
	while (tok_count <= 6)
	{
		if (tok_count >= 4)
			return (ft_show_error("Too much parameteres", 0, -1));
		while (line->content[start] && ft_isspace(line->content[start]))
			start++;
		end = start;
		while (line->content[end] && !ft_isspace(line->content[end])
			&& line->content[end] != SEPARATOR_CHAR)
			end++;
		if (ft_add_token(line, start, end, tok_count) == -1)
			return (ft_show_error("Can't add token", 0, -1));
		start = end + 1;
		if (!line->content[start - 1])
			break ;
		tok_count++;
	}
	line->nb_params = tok_count;
	return (0);
}
