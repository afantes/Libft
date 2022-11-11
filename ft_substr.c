/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:08:38 by afantes           #+#    #+#             */
/*   Updated: 2022/10/30 21:55:21 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	noleaks(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s + start) >= len)
		return (len);
	else
		return (ft_strlen(s + start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (s == '\0')
		return (0);
	if (ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	p = malloc((noleaks(s, start, len) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
