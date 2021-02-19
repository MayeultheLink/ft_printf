/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:33:32 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/02/19 16:17:55 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_print(va_list args, char *input)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '%')
			fonction parsing
		else
		{
			write(1, input[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int		ft_printf(const char *input, ...)
{
	va_list		args;
	int			count;

	va_start(args, input);
	count = get_print(input, args);
	va_end(args);
	return (count);
}
