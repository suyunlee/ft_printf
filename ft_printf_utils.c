/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:06:26 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 20:45:25 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_count(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

int		hexoctnum_count(unsigned long long unum, char type)
{
	int	count;

	count = 0;
	if (type == 'x' || type == 'p' || type == 'X')
	{
		while (unum >= 16)
		{
			unum = unum / 16;
			count++;
		}
	}
	if (type == 'o')
	{
		while (unum >= 8)
		{
			unum = unum / 8;
			count++;
		}
	}
	count++;
	return (count);
}

void	print_hexoctnum(unsigned long long unum, char type)
{
	char	*xnum;
	char	*xxnum;
	char	*onum;

	xnum = "0123456789abcdef";
	xxnum = "0123456789ABCDEF";
	onum = "01234567";
	if (type == 'x' || type == 'p')
	{
		if (unum >= 16)
			print_hexoctnum(unum / 16, type);
		ft_putchar_fd(xnum[unum % 16], 1);
	}
	if (type == 'X')
	{
		if (unum >= 16)
			print_hexoctnum(unum / 16, type);
		ft_putchar_fd(xxnum[unum % 16], 1);
	}
	if (type == 'o')
	{
		if (unum >= 8)
			print_hexoctnum(unum / 8, type);
		ft_putchar_fd(onum[unum % 8], 1);
	}
}

void	print_dminus_two(t_options specifier, int zcount, int *num)
{
	if (*num < 0 && *num != -2147483648)
	{
		ft_putchar_fd('-', 1);
		*num *= -1;
	}
	if (*num == -2147483648 && specifier.zero == 0)
		ft_putchar_fd('-', 1);
	while (zcount-- > 0)
		ft_putchar_fd('0', 1);
	if (*num == -2147483648)
	{
		ft_putchar_fd('2', 1);
		*num = 147483648;
	}
}

void	print_zcount(t_options specifier, int zcount)
{
	if (specifier.zero == 0)
		ft_putstr_fd("0x", 1);
	while (zcount-- > 0)
		ft_putchar_fd('0', 1);
}
