/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 08:11:09 by arbib             #+#    #+#             */
/*   Updated: 2019/05/04 00:54:35 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				ft_check_label(char *str)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	if (str[i - 1] == LABEL_CHAR)
	{
		while (j < i - 1)
		{
			if (is_label_char(str[j]) == 0)
				return (ft_show_error("Label in wrong format", 0, -1));
			j++;
		}
		return (i - 1);
	}
	return (0);
}

void			ft_clean_lines(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR)
			break ;
		i++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

int				ft_init_line(t_root *root, char *str, int type_line)
{
	t_line		*line;
	t_line		*tmp;

	tmp = root->lines;
	if (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		return (-1);
	line->num = root->i;
	line->content = ft_strtrim(str);
	line->tokens = NULL;
	line->type = type_line;
	line->next = NULL;
	ft_bzero(line->bytecode, 14);
	line->byte_len = 0;
	if (root->lines == NULL)
		root->lines = line;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = line;
	}
	root->i++;
	return (0);
}

int				ft_addline(t_root *root, char *str, int labelcheck)
{
	int			size;

	ft_clean_lines(str);
	size = ft_strlen(str);
	if (labelcheck > 0)
	{
		str[labelcheck + 1] = 0;
		if (ft_init_line(root, str, T_Label) == -1)
			return (-1);
		str[labelcheck + 1] = ' ';
		if (size != labelcheck + 1)
			if (!ft_is_whitespace(&str[labelcheck + 1]))
				if (ft_init_line(root, str + labelcheck + 1, T_Unknown) == -1)
					return (-1);
	}
	else if (labelcheck == 0)
	{
		if (!ft_is_whitespace(str) &&
				ft_init_line(root, str, T_Unknown) == -1)
			return (-1);
	}
	else if (labelcheck == -1)
		return (-1);
	return (0);
}

int				ft_check_read(t_root *root)
{
	char		*str;
	int			file_return;

	file_return = 1;
	str = NULL;
	while ((file_return = get_next_line(root->fd_in, &str)) > 0)
	{
		if (str && (!(*str) || ft_is_whitespace(str) || str[0] == COMMENT_CHAR))
		{
			free(str);
			continue;
		}
		if (ft_addline(root, str, ft_check_label(str)))
		{
			free(str);
			return (ft_show_error("Can't initiate line", root->i, -1));
		}
		free(str);
	}
	free(str);
	if (file_return == -1)
		return (ft_show_error("Can't get lines from file", 0, -1));
	if (root->i == 0)
		return (ft_show_error("Empty file given", 0, -1));
	return (0);
}
