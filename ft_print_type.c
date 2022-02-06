/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:46:33 by suylee            #+#    #+#             */
/*   Updated: 2020/12/22 21:25:00 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(t_options specifier, va_list ap)
{
	int num;
	int fcount;
	int zcount;
	int	mcount;

	fcount = 0;
	zcount = 0;
	mcount = 0;
	if (specifier.type == 'd' || specifier.type == 'i')
	{
		num = va_arg(ap, int);
		if (num == 0 && specifier.dot == 0)
			return (print_intnul(specifier));
		fcount = num_count(num);
		precision_int(&specifier, &fcount, &zcount);
		print_dminus(specifier, &num, &mcount, &fcount);
		if (specifier.minus == 0)
			fcount = flag(specifier, fcount);
		print_dminus_two(specifier, zcount, &num);
		ft_putnbr_fd(num, 1);
		if (specifier.minus == 1)
			fcount = flag(specifier, fcount);
	}
	return (fcount + mcount);
}

int	print_s(t_options specifier, va_list ap)
{
	int		fcount;
	int		count;
	int		index;
	char	*str;

	fcount = 0;
	index = -1;
	count = 0;
	if (specifier.type == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		fcount = ft_strlen(str);
		precision_str(specifier, str, &fcount);
		if (specifier.minus == 0)
			count = flag(specifier, fcount);
		while (++index < fcount)
			ft_putchar_fd(str[index], 1);
		if (specifier.minus == 1)
			count = flag(specifier, fcount);
	}
	fcount = count;
	return (fcount);
}

int	print_c(t_options specifier, va_list ap)
{
	int		fcount;
	char	c;

	fcount = 0;
	if (specifier.type == 'c')
	{
		c = va_arg(ap, int);
		if (specifier.minus == 0)
			fcount = flag(specifier, 1);
		ft_putchar_fd(c, 1);
		if (specifier.minus == 1)
			fcount = flag(specifier, 1);
	}
	return (fcount);
}

int	print_x(t_options specifier, va_list ap)
{
	int				fcount;
	int				zcount;
	unsigned int	xnum;

	fcount = 0;
	zcount = 0;
	if (specifier.type == 'x' || specifier.type == 'X')
	{
		xnum = va_arg(ap, unsigned int);
		if (xnum == 0 && specifier.dot == 0)
			return (print_intnul(specifier));
		fcount = hexoctnum_count(xnum, specifier.type);
		precision_int(&specifier, &fcount, &zcount);
		if (specifier.minus == 0)
			fcount = flag(specifier, fcount);
		while (zcount-- > 0)
			ft_putchar_fd('0', 1);
		print_hexoctnum(xnum, specifier.type);
		if (specifier.minus == 1)
			fcount = flag(specifier, fcount);
	}
	return (fcount);
}

int	print_o(t_options specifier, va_list ap)
{
	int				fcount;
	int				zcount;
	unsigned int	onum;

	fcount = 0;
	zcount = 0;
	if (specifier.type == 'o')
	{
		onum = va_arg(ap, unsigned int);
		if (onum == 0 && specifier.dot == 0)
			return (print_intnul(specifier));
		fcount = hexoctnum_count(onum, specifier.type);
		precision_int(&specifier, &fcount, &zcount);
		if (specifier.minus == 0)
			fcount = flag(specifier, fcount);
		while (zcount-- > 0)
			ft_putchar_fd('0', 1);
		print_hexoctnum(onum, specifier.type);
		if (specifier.minus == 1)
			fcount = flag(specifier, fcount);
	}
	return (fcount);
}
