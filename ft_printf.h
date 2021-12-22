/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:03:16 by bbali             #+#    #+#             */
/*   Updated: 2021/12/22 14:11:39 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_nbrlen(long nbr);
int		ft_nbrlenu(unsigned int n);
int		ft_putnbru(unsigned int n);
void	ft_puthexa(unsigned long long p, char c);
int		ft_hexalen(unsigned long long p);
int		ft_putptr(unsigned long long p, char c);
int		ft_print_hexa(unsigned int n, char c);
int		ft_printf(const char *s, ...);
int		is_valid_args(const char *s);

#endif