/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:00:45 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 20:38:15 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(t_options specifier, va_list ap)
{
	unsigned int	num;
	int				fcount;
	int				zcount;

	fcount = 0;
	zcount = 0;
	if (specifier.type == 'u')
	{
		num = va_arg(ap, unsigned int);
		if (num == 0 && specifier.dot == 0)
			return (print_intnul(specifier));
		fcount = unsignednum_count(num);
		precision_int(&specifier, &fcount, &zcount);
		if (specifier.minus == 0)
			fcount = flag(specifier, fcount);
		while (zcount-- > 0)
			ft_putchar_fd('0', 1);
		print_unsignedint(num);
		if (specifier.minus == 1)
			fcount = flag(specifier, fcount);
	}
	return (fcount);
}

int	print_percent(t_options specifier)
{
	int fcount;

	fcount = 0;
	if (specifier.type == '%')
	{
		fcount = 1;
		specifier.dot = -1;
		if (specifier.minus == 1 || specifier.width == 0)
			specifier.zero = 0;
		if (specifier.minus == 0)
			fcount = flag(specifier, fcount);
		ft_putchar_fd('%', 1);
		if (specifier.minus == 1)
			fcount = flag(specifier, fcount);
	}
	return (fcount);
}

int	print_p(t_options specifier, va_list ap)
{
	int					fcount;
	int					zcount;
	unsigned long long	pointer;

	fcount = 0;
	zcount = 0;
	if (specifier.type == 'p')
	{
		pointer = va_arg(ap, unsigned long long);
		fcount = hexoctnum_count(pointer, specifier.type) + 2;
		if (pointer == 0)
			print_pnul(specifier, &fcount, &zcount);
		else
		{
			precision_p(&specifier, &fcount, &zcount);
			if (specifier.minus == 0)
				fcount = flag(specifier, fcount);
			print_zcount(specifier, zcount);
			print_hexoctnum(pointer, specifier.type);
			if (specifier.minus == 1)
				fcount = flag(specifier, fcount);
		}
	}
	return (fcount);
}
