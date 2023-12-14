/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:52:23 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/14 17:20:00 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	a;
	char	*str;

	a = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != a)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return (str);
}
