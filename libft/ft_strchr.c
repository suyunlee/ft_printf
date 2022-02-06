/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:20:35 by suylee            #+#    #+#             */
/*   Updated: 2020/10/21 14:37:31 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	if (c == 0)
	{
		while (*str)
			str++;
		return (str);
	}
	else
	{
		while (*str)
		{
			if (*str == c)
				break ;
			str++;
		}
		if (*str == '\0')
			return (NULL);
		else
			return (str);
	}
}
