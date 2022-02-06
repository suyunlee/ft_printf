/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_untils_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:13:05 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 20:41:28 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsignednum_count(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count = 1;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

void	print_unsignedint(unsigned int num)
{
	char	*digit;

	digit = "0123456789";
	if (num >= 10)
		print_unsignedint(num / 10);
	ft_putchar_fd(digit[num % 10], 1);
}

void	print_pnul(t_options specifier, int *fcount, int *zcount)
{
	if (specifier.dot >= 0)
		*fcount = 2;
	else
		*fcount = 3;
	precision_p(&specifier, fcount, zcount);
	if (specifier.dot < 0 && specifier.zero == 1)
		ft_putchar_fd('0', 1);
	if (specifier.minus == 0)
		*fcount = flag(specifier, *fcount);
	if (specifier.dot >= 0 && specifier.zero == 0)
		ft_putstr_fd("0x", 1);
	else if (specifier.zero == 0)
		ft_putstr_fd("0x0", 1);
	while (*zcount-- > 0)
		ft_putchar_fd('0', 1);
	if (specifier.minus == 1)
		*fcount = flag(specifier, *fcount);
}

int		print_intnul(t_options specifier)
{
	int i;

	i = specifier.width;
	if (specifier.width == 0)
		return (0);
	if (specifier.width > 0)
	{
		while (i > 0)
		{
			ft_putchar_fd(' ', 1);
			i--;
		}
	}
	return (specifier.width);
}

void	print_dminus(t_options specifier, int *num, int *mcount, int *fcount)
{
	if (*num < 0)
	{
		if (specifier.zero == 1)
		{
			ft_putchar_fd('-', 1);
			if (*num != -2147483648)
				*num *= -1;
			if (specifier.dot >= 0)
				*mcount = 1;
			else
				*fcount += 1;
		}
		else
			*fcount += 1;
	}
}
