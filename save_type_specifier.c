/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_type_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:38:08 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 21:06:55 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		save_flag(t_options *specifier, char *format, va_list ap)
{
	while (format[specifier->index] == '-' || format[specifier->index] == '+'
			|| format[specifier->index] == '0')
	{
		if (format[specifier->index] == '-')
			specifier->minus = 1;
		if (format[specifier->index] == '0')
			specifier->zero = 1;
		specifier->index++;
	}
	if (format[specifier->index] == '*')
	{
		specifier->width = va_arg(ap, int);
		specifier->index++;
	}
}

void		save_width(t_options *specifier, char *format)
{
	if (specifier->width == 0)
	{
		while (format[specifier->index] >= '0'
				&& format[specifier->index] <= '9')
		{
			specifier->width *= 10;
			specifier->width += (format[specifier->index] - '0');
			specifier->index++;
		}
	}
	if (specifier->width < 0)
	{
		specifier->minus = 1;
		specifier->width *= -1;
		specifier->zero = 0;
	}
}

void		save_precision(t_options *specifier, char *format, va_list ap)
{
	if (format[specifier->index] == '.')
	{
		specifier->dot = 0;
		specifier->index++;
	}
	if (format[specifier->index] == '*')
	{
		specifier->dot = va_arg(ap, int);
		specifier->index++;
	}
	else
	{
		while (format[specifier->index] >= '0'
				&& format[specifier->index] <= '9')
		{
			specifier->dot *= 10;
			specifier->dot += format[specifier->index] - '0';
			specifier->index++;
		}
	}
}

void		save_type(t_options *specifier, char *format)
{
	char	*spec;

	spec = "cspdiuxX%nfgeo";
	while (*spec)
	{
		if (format[specifier->index] == *spec)
		{
			specifier->type = *spec;
			break ;
		}
		spec++;
	}
	if (specifier->type != '%' && specifier->dot >= 0
			&& specifier->zero == 1)
		specifier->zero = 0;
	if (specifier->minus == 1)
		specifier->zero = 0;
}

t_options	save_type_specifier(char *format, va_list ap,
			int index, int *fcount)
{
	t_options specifier;

	specifier.minus = 0;
	specifier.zero = 0;
	specifier.width = 0;
	specifier.dot = -1;
	specifier.type = 0;
	specifier.index = index;
	if (format[specifier.index] == ' ')
	{
		*fcount += 1;
		ft_putchar_fd(' ', 1);
		specifier.index++;
	}
	while (format[specifier.index] == ' ')
		specifier.index++;
	save_flag(&specifier, format, ap);
	save_width(&specifier, format);
	save_precision(&specifier, format, ap);
	save_type(&specifier, format);
	return (specifier);
}
