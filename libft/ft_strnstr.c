/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:49:03 by mde-la-s          #+#    #+#             */
/*   Updated: 2020/12/18 14:23:12 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)s1;
	if (s2[i] == 0)
		return (&str[i]);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i] && s1[i] != s2[j] && i < len)
			i++;
		while (s1[i] && s2[j] && s1[i] == s2[j] && i < len)
		{
			j++;
			i++;
		}
		if (s2[j] == 0)
			return (&str[i - j]);
	}
	return (0);
}
