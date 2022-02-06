/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:31:04 by suylee            #+#    #+#             */
/*   Updated: 2020/10/24 14:47:55 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isisspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	issign(const char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && isisspace(nptr[i]) == 1)
		i++;
	if (issign(nptr[i]) != 0)
	{
		sign = issign(nptr[i]);
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	result = sign * result;
	return (result);
}
