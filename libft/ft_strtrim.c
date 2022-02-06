/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:14:02 by suylee            #+#    #+#             */
/*   Updated: 2020/10/26 16:09:04 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isset(char c, char const *set)
{
	int i;

	i = 0;
	while (((char *)set)[i])
	{
		if (c == ((char *)set)[i])
			return (1);
		i++;
	}
	return (0);
}

int		endindex(char *s1, char const *set)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	while (isset(((char *)s1)[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		end;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (isset(((char *)s1)[start], set) == 1)
		start++;
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	end = endindex((char *)s1, set);
	len = end - start + 1;
	result = ft_substr(s1, start, len);
	return (result);
}
