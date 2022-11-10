/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:27:13 by afantes           #+#    #+#             */
/*   Updated: 2022/10/30 21:57:54 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*u;

	u = (char *)s;
	i = ft_strlen(u);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return (u + i);
		i--;
	}
	return (0);
}
