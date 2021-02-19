/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:39:19 by mde-la-s          #+#    #+#             */
/*   Updated: 2020/12/16 12:52:37 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nblen(int n)
{
	size_t	i;

	i = 0;
	i += (n <= 0 ? 1 : 0);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			i;
	unsigned int	n_uns;

	i = ft_nblen(n);
	n_uns = n;
	if (!(s = malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n_uns *= -1;
	}
	s[i] = 0;
	i -= 1;
	while (n_uns >= 10)
	{
		s[i] = (n_uns % 10) + 48;
		n_uns /= 10;
		i--;
	}
	s[i] = n_uns % 10 + 48;
	return (s);
}
