/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:24:26 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/09 17:45:38 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == 0) && str[i] != c)
		{
			words++;
		}
		i++;
	}
	return (words);
}

static char	*ft_strdupp(char *src, char charset)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != charset && src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != charset && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**free_error(char **tab, int pos)
{
	int	i;

	i = 0;
	while (i <= pos)
		free(tab[i++]);
	return (free(tab), NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc ((countwords((char *)s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < countwords((char *)s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		tab[i] = ft_strdupp((char *)&s[j], c);
		if (!tab[i])
			return (free_error(tab, i));
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	return (tab[i] = NULL, tab);
}
