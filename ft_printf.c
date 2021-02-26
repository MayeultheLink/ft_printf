/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:33:32 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/02/26 16:35:37 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ap(char *input, va_list ap, int i)
{
	char	c;
	int		d;
	char	*s;
	int		count;

	count = 0;
	while (input[i] != 'c' && input[i] != 'd' && input[i] != 's')
	{
		if (input[i + 1] == '%')
		{
			write(1, "%", 1);
			count++;
			break ;
		}
		if (input[i + 1] == 'c')
		{
			c = va_arg(ap, int);
			write(1, &c, 1);
			count++;
		}
		if (input[i + 1] == 'd')
		{
			d = va_arg(ap, int);
			s = ft_itoa(d);
			count += ft_strlen(s);
			write(1, s, count);
		}
		if (input[i + 1] == 's')
		{
			s = va_arg(ap, char*);
			count += ft_strlen(s);
			write(1, s, count);
		}
		i++;
	}
	return (count);
}

int		get_print(va_list ap, char *input)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += print_ap(input, ap, i);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int		ft_printf(const char *input, ...)
{
	va_list		ap;
	int			count;
	char		*str;

	str = ft_strdup(input);
	va_start(ap, input);
	count = get_print(ap, str);
	va_end(ap);
	free(str);
	return (count);
}

int		main()
{
	int	i;
	int j;
	char c;
	int h;
	char *str;

	c = 'g';
	h = 12;
	str = "mmmm";
	i = ft_printf("[%dhello %s world%%%c] = ft_printf\n", h, str, c);
	j = printf("[%dhello %s world%%%c] = printf\n", h, str, c);
	if (i == j + 3)
		printf("retour ok");
	else
		printf("mauvais retour : i = %d / j = %d\n", i, (j + 3));
	return (0);
}
