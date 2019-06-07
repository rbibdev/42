/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:18:36 by arbib             #+#    #+#             */
/*   Updated: 2017/11/07 19:18:41 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;
	int sum;

	if (nb == 0)
		return (1);
	if (nb > 0 && nb < 13)
	{
		sum = 1;
		i = 1;
		while (i < nb)
		{
			sum += ft_recursive_factorial(i) * i;
			i++;
		}
	}
	else
	{
		return (0);
	}
	return (sum);
}
