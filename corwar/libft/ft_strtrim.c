/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbib <arbib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:09:26 by arbib             #+#    #+#             */
/*   Updated: 2019/04/30 22:35:55 by arbib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s1)
{
	register size_t	i;
	char			*s2;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isspace(s1[i]))
		++i;
	s2 = ft_strdup(&s1[i]);
	i = ft_strlen(s2) - 1;
	while (s2[i] && ft_isspace(s2[i]))
		s2[i--] = '\0';
	return (s2);
}
