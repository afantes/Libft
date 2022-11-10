/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:43:48 by afantes           #+#    #+#             */
/*   Updated: 2022/10/24 22:21:13 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = count * size;
	if (count != 0 && size != (tot_size / count))
		return (0);
	dst = malloc(tot_size);
	if (dst == 0)
		return (NULL);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
