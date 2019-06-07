/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:35:53 by arbib             #+#    #+#             */
/*   Updated: 2017/11/15 20:24:19 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int k;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			k = 0;
			while (to_find[k] == str[i + k])
			{
				k++;
				if (to_find[k] == '\0')
				{
					return ((char *)&str[i]);
				}
			}
		}
		i++;
	}
	return (0);
}
