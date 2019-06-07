/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 01:13:33 by arbib             #+#    #+#             */
/*   Updated: 2019/05/04 04:43:51 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				ft_write_magic(int fd)
{
	int			magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	write(fd, (char *)&magic, 4);
	return (0);
}

int				ft_write_name_comm_size(int fd, t_header header)
{
	char		buf[4];
	char		size_prog[4];

	ft_bzero(buf, 4);
	ft_trans_tk_val(header.prog_size, size_prog, 4, &(header.prog_size));
	write(fd, header.prog_name, PROG_NAME_LENGTH);
	write(fd, buf, 4);
	write(fd, size_prog, 4);
	write(fd, header.comment, COMMENT_LENGTH);
	write(fd, buf, 4);
	return (0);
}

int				ft_write_instructions(t_root *root)
{
	t_line		*tmp;

	tmp = root->lines;
	while (tmp)
	{
		if (*(tmp->bytecode))
			write(root->fd_out, tmp->bytecode, tmp->byte_len);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_write_champ(t_root *root)
{
	if (root->header.prog_size > CHAMP_MAX_SIZE)
		return (ft_show_error("Champs is over size", 0, -1));
	if (root->i == 0)
		return (ft_show_error("No instruction found", 0, -1));
	if (!(root->fd_out = open(root->out_file,
				O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		return (ft_show_error("Faild to create champ file", 0, -1));
	ft_write_magic(root->fd_out);
	ft_write_name_comm_size(root->fd_out, root->header);
	ft_write_instructions(root);
	return (ft_show_error("Champ has been created succesfully !", 0, 0));
}
