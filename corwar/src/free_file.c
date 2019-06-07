/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 02:48:17 by arbib             #+#    #+#             */
/*   Updated: 2019/05/07 18:55:56 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void		ft_free_tokens(t_list *tokens)
{
	t_list	*tmp;
	t_list	*next;
	t_token	*tk;

	if (!(tmp = tokens))
		return ;
	while (tmp)
	{
		tk = ft_get_token(tmp);
		next = tmp->next;
		free(tk->content);
		if (tk->op)
			free(tk->op);
		free(tk);
		free(tmp);
		tmp = next;
	}
}

void		ft_free_lines(t_root *root)
{
	t_line	*tmp;
	t_line	*next;

	tmp = root->lines;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		ft_free_tokens(tmp->tokens);
		free(tmp);
		tmp = next;
	}
}

int			ft_finish_it(t_root *root)
{
	if (root->out_file)
		free(root->out_file);
	close(root->fd_in);
	close(root->fd_out);
	ft_free_lines(root);
	return (0);
}
