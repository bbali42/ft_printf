/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:47:12 by bbali             #+#    #+#             */
/*   Updated: 2021/12/22 15:37:51 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_conversion(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long long), c));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	is_valid_args(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] != 'c' && s[i + 1] != 's' && s[i + 1] != 'p' && \
			s[i + 1] != 'd' && s[i + 1] != 'i' && s[i + 1] != 'u' && \
			s[i + 1] != 'x' && s[i + 1] != 'X' && s[i + 1] != '%')
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (is_valid_args(s))
	{
		va_start(args, s);
		while (s[i])
		{
			if (s[i] == '%')
			{
				count += get_conversion(args, s[i + 1]);
				i++;
			}
			else
				count += write(1, &s[i], 1);
			i++;
		}
		va_end(args);
	}
	return (count);
}
