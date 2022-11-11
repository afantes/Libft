/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:20:52 by afantes           #+#    #+#             */
/*   Updated: 2022/10/25 01:18:04 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_nb(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*putnbchar(long int n, int i, char *str)
{
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char		*str;
	long int	n;
	int			i;

	n = nb;
	i = len_nb(n);
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i -= 1;
	return (putnbchar(n, i, str));
}
