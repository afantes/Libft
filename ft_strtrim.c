/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:33:15 by afantes           #+#    #+#             */
/*   Updated: 2022/10/20 23:50:51 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_here(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;
	char	*p;

	if (!s1 || !set)
		return (0);
	l = ft_strlen(s1);
	i = 0;
	while (s1[i] && is_here(s1[i], set) == 1)
		i++;
	if (i == l)
		return (ft_strdup(""));
	while (is_here(s1[l - 1], set) == 1)
		l--;
	p = ft_substr(s1, i, l - i);
	return (p);
}
