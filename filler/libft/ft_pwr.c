/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:50:26 by arbib             #+#    #+#             */
/*   Updated: 2017/11/22 00:54:47 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_pwr(int nb, int power)
{
	int i;
	int sum;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	sum = nb;
	while (i < power)
	{
		sum = nb * ft_pwr(nb, i);
		i++;
	}
	return (sum);
}
