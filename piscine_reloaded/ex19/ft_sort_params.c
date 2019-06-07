/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:26:48 by arbib             #+#    #+#             */
/*   Updated: 2017/11/07 19:26:52 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s2++;
		s1++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 1;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
				{
					c = argv[i];
					argv[i] = argv[j];
					argv[j] = c;
				}
				j++;
			}
			ft_putstr(argv[i]);
		}
	}
	return (0);
}
