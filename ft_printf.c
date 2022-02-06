/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:27:23 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 16:35:05 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_type(t_options specifier, va_list ap)
{
	int fcount;

	fcount = 0;
	fcount += print_s(specifier, ap);
	fcount += print_d(specifier, ap);
	fcount += print_c(specifier, ap);
	fcount += print_x(specifier, ap);
	fcount += print_o(specifier, ap);
	fcount += print_u(specifier, ap);
	fcount += print_percent(specifier);
	fcount += print_p(specifier, ap);
	return (fcount);
}

int	ft_printf(char *format, ...)
{
	va_list		ap;
	int			fcount;
	t_options	specifier;

	va_start(ap, format);
	fcount = 0;
	specifier.index = -1;
	while (format[++specifier.index])
	{
		if (format[specifier.index] == '%')
		{
			specifier.index++;
			specifier = save_type_specifier(format, ap,
					specifier.index, &fcount);
			if (specifier.type == 0)
				return (0);
			fcount += printf_type(specifier, ap);
		}
		else
		{
			ft_putchar_fd(format[specifier.index], 1);
			fcount++;
		}
	}
	return (fcount);
}
