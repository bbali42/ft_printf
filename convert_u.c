/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:46:56 by bbali             #+#    #+#             */
/*   Updated: 2021/12/22 14:05:08 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlenu(unsigned int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbru(unsigned int n)
{
	int		len;

	len = ft_nbrlenu(n);
	if (n > 9)
		ft_putnbru(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}
