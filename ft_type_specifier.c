/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:32:17 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 20:44:43 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag(t_options specifier, int count)
{
	int	blank;
	int	fcount;

	blank = 0;
	fcount = count;
	if (specifier.width > count)
	{
		blank = specifier.width - count;
		fcount = specifier.width;
	}
	if (specifier.zero == 1 && specifier.type != 'c')
	{
		while (blank-- > 0)
			ft_putchar_fd('0', 1);
	}
	else
	{
		while (blank-- > 0)
			ft_putchar_fd(' ', 1);
	}
	return (fcount);
}

void	precision_int(t_options *specifier, int *fcount, int *zcount)
{
	if (specifier->dot > *fcount)
	{
		if (specifier->width < specifier->dot)
		{
			specifier->width = specifier->dot;
			specifier->zero = 1;
			specifier->minus = 0;
		}
		else
		{
			specifier->zero = 0;
			*zcount = specifier->dot - *fcount;
			*fcount = specifier->dot;
		}
	}
	if (specifier->dot >= 0 && specifier->dot < *fcount)
		specifier->zero = 0;
}

void	precision_str(t_options specifier, char *str, int *fcount)
{
	if (specifier.dot >= 0 && specifier.dot < (int)ft_strlen(str))
		*fcount = specifier.dot;
}

void	precision_p(t_options *specifier, int *fcount, int *zcount)
{
	if (specifier->dot > *fcount)
	{
		if (specifier->width < specifier->dot)
		{
			specifier->width = specifier->dot + 2;
			specifier->zero = 1;
			specifier->minus = 0;
		}
		else
		{
			specifier->zero = 0;
			*zcount = specifier->dot - *fcount;
			*fcount = specifier->dot;
		}
	}
	if (specifier->dot >= 0 && specifier->dot < *fcount)
		specifier->zero = 0;
	if (specifier->zero == 1)
		ft_putstr_fd("0x", 1);
}
