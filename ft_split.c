/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:35:56 by afantes           #+#    #+#             */
/*   Updated: 2022/10/30 19:41:06 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_of_words(char *s, char c)
{
	size_t	i;
	size_t	h;
	size_t	l;

	i = 0;
	h = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && h == 0)
		{
			l++;
			h = 1;
		}
		else if (s[i] == c && h == 1)
			h = 0;
		i++;
	}
	return (l);
}

static char	**free_all(char **p, size_t u)
{
	while (u >= 0)
	{
		free(p[u]);
		p[u] = NULL;
		u--;
	}
	free(p);
	p = NULL;
	return (NULL);
}

static char	**putword(char *s, char c, char **p)
{
	size_t	i;
	size_t	j;
	size_t	u;

	i = 0;
	u = 0;
	while (u < nbr_of_words((char *)s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		p[u] = ft_substr((char *)s, i, j - i);
		if (p[u] == NULL)
			return (free_all(p, u));
		i = j;
		u++;
	}
	p[u] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (0);
	p = malloc((nbr_of_words((char *)s, c) + 1) * (sizeof(char *)));
	if (!p)
		return (NULL);
	return (putword((char *)s, c, p));
}
