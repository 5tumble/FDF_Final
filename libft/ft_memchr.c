/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:44:21 by rukoltso          #+#    #+#             */
/*   Updated: 2023/01/17 13:53:33 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const char 	*str;

	i = 0;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return (void *)(s + i);
		i++;
	}
	return (0);
}
