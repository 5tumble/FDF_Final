/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:46:36 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/14 16:46:39 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buc;

	i = 0;
	buc = (unsigned char *)s;
	while (i < n)
	{
		buc[i] = c;
		i++;
	}
	return (s = buc);
}
