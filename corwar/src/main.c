/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 07:49:22 by arbib             #+#    #+#             */
/*   Updated: 2019/05/04 01:42:20 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				ft_show_error(char *msg, int ligne, int err)
{
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	if (ligne > 0)
	{
		ft_putstr_fd("Error in ligne : ", 2);
		ft_putnbr_fd(ligne, 2);
	}
	return (err);
}

void			ft_init_asm(t_root *root)
{
	ft_bzero(root->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(root->header.comment, COMMENT_LENGTH + 1);
	root->header.magic = COREWAR_EXEC_MAGIC;
	root->header.prog_size = 0;
	root->lines = NULL;
	root->in_file = NULL;
	root->out_file = NULL;
	root->nb_lines = 0;
	root->fd_in = -2;
	root->fd_out = -2;
	root->i = 1;
	return ;
}

char			*ft_get_champ(t_root *root)
{
	int			size;

	size = 0;
	root->out_file = ft_strrchr(root->in_file, '.');
	if (!root->out_file)
		return (NULL);
	if (ft_strcmp(root->out_file, ".s") != 0)
		return (NULL);
	size = ft_strlen(root->in_file) - ft_strlen(root->out_file);
	root->out_file = ft_strnew(size + 4);
	ft_strncpy(root->out_file, root->in_file, size + 1);
	ft_strncpy(&root->out_file[size + 1], "cor", 3);
	return (root->out_file);
}

int				main(int argc, char **argv)
{
	t_root		root;

	ft_bzero(&root, sizeof(t_root));
	if (argc < 2 || argc >= 3)
		return (ft_show_error("\nIncorrect param number! try again\n", 0, -1));
	else
		ft_init_asm(&root);
	root.in_file = argv[1];
	if (!(root.out_file = ft_get_champ(&root)))
		return (ft_show_error("\nIncompatible File! try again", 0, -1));
	if ((root.fd_in = open(argv[1], O_RDONLY)) == -1)
		return (ft_show_error("\nCan't open file! try again", 0, -1));
	if (ft_check_read(&root) || ft_parse_file(&root))
	{
		ft_finish_it(&root);
		return (ft_show_error("\nCan't read or parse file! try again", 0, -1));
	}
	if (ft_strlen(root.header.prog_name) > 0 && ft_convertion_file(&root) == 0)
		ft_write_champ(&root);
	else
		ft_show_error("\nChamp has no name or Convertion failed\n", 0, -1);
	ft_finish_it(&root);
	return (0);
}
