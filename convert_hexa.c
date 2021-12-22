/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:55:27 by bbali             #+#    #+#             */
/*   Updated: 2021/12/22 14:05:11 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (1);
	while (p != 0)
	{
		len++;
		p = p / 16;
	}
	return (len);
}

void	ft_puthexa(unsigned long long p, char c)
{
	if (p >= 16)
	{
		ft_puthexa(p / 16, c);
		ft_puthexa(p % 16, c);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
		{
			if (c == 'x' || c == 'p')
				ft_putchar(p - 10 + 'a');
			else if (c == 'X')
				ft_putchar(p - 10 + 'A');
		}
	}
}

int	ft_putptr(unsigned long long p, char c)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	else
	{
		ft_puthexa(p, c);
		len += ft_hexalen(p);
	}
	return (len);
}

int	ft_print_hexa(unsigned int n, char c)
{
	int	len;

	len = 0;
	ft_puthexa(n, c);
	len += ft_hexalen(n);
	return (len);
}
