/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:12:49 by afantes           #+#    #+#             */
/*   Updated: 2022/10/20 20:06:13 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	l;
	size_t	i;
	size_t	j;

	if (size == 0 || size < ft_strlen(dst))
		return (size + ft_strlen(src));
	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	l = ls + ld;
	i = 0;
	j = ld;
	while (src[i] != '\0' && j < size - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (l);
}
