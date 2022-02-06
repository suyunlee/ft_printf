/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:39:16 by suylee            #+#    #+#             */
/*   Updated: 2020/10/30 10:46:30 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (!s[0])
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char			**ft_sfree(char **dest)
{
	unsigned int i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static char			**ft_fill(char const *s, char c, char **result)
{
	unsigned int	r_index;
	unsigned int	s_index;
	unsigned int	counttwo;
	unsigned int	count;

	r_index = 0;
	s_index = 0;
	count = ft_count(s, c);
	result[count] = 0;
	while (r_index < count)
	{
		counttwo = 0;
		while (s[s_index] == c)
			s_index++;
		while (s[s_index] != c && s[s_index])
		{
			s_index++;
			counttwo++;
		}
		if (!(result[r_index] = ft_substr(s, s_index - counttwo, counttwo)))
			return (ft_sfree(result));
		r_index++;
	}
	return (result);
}

char				**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (count == 0)
	{
		result[count] = 0;
		return (result);
	}
	result = ft_fill(s, c, result);
	return (result);
}
