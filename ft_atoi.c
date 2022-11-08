/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:50:25 by afantes           #+#    #+#             */
/*   Updated: 2022/10/21 19:12:29 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(long long prev, long long curr)
{
	if (curr / 10 == prev)
		return (0);
	return (1);
}

static int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_sign(const char *str, int *ptri)
{
	int	i;
	int	sign;

	i = ft_space(str);
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	*ptri = i;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		res;
	long long		prev;

	sign = ft_sign(str, &i);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = res;
		res = res * 10 + (str[i] - '0');
		if (ft_overflow(prev, res) == 1)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	res *= sign;
	return (res);
}
