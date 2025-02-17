/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:46:44 by oyozcan           #+#    #+#             */
/*   Updated: 2023/07/14 18:05:15 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	new;

	count = 0;
	new = 1;
	while (*str)
	{
		if (*str != c && new == 1)
		{
			count++;
			new = 0;
		}
		if (*str == c)
			new = 1;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**tab;

	tab = (char **) ft_calloc (count_words(s, c) + 1, sizeof(char *));
	if (!tab || !s)
		return (0);
	i = 0;
	size = 0;
	while (*s)
	{
		if (*s != c)
			size++;
		if (*s == c && size > 0)
		{
			tab[i] = ft_substr((s - size), 0, size);
			i++;
			size = 0;
		}
		s++;
	}
	if (size > 0)
		tab[i] = ft_substr((s - size), 0, size);
	return (tab);
}
