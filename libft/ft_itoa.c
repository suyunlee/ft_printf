/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:02:26 by suylee            #+#    #+#             */
/*   Updated: 2020/10/21 15:57:43 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		numlen(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	len = numlen(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (len > 0)
	{
		len--;
		if ((n % 10) < 0)
			result[len] = n % 10 * -1 + '0';
		else
			result[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
