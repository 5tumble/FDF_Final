/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:33:59 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/14 17:34:30 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_digit(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	convert(int i, const char *str, int sign)
{
	long int	result;

	result = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (result * sign < -2147483647 - 1)
		return (0);
	else if (result * sign > 2147483647)
		return (0);
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	nbr;

	if (nptr[0] == '\0')
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	if (check_digit(nptr) == 0)
		return (0);
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	if (ft_isdigit(nptr[i]) == 1)
	{
		nbr = convert(i, nptr, sign);
		return (nbr * sign);
	}
	else
		return (0);
}
