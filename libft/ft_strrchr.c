/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:22:49 by suylee            #+#    #+#             */
/*   Updated: 2020/10/21 15:46:37 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last;

	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = s;
		s++;
	}
	if (last == NULL)
		return (0);
	else
		return ((char *)last);
}
