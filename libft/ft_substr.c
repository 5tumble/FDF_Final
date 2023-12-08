/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:50:54 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/04 16:01:09 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*dst;
	size_t	new_len;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
	{
		dst = malloc(sizeof(char));
		dst[0] = 0;
		if (!dst)
			return (NULL);
	}
	else
	{
		new_len = ft_strlen(str + start);
		if (!(new_len < len))
			new_len = len;
		dst = (char *)malloc((new_len + 1) * sizeof(char));
		if (!dst)
			return (NULL);
		dst[new_len] = 0;
		while (new_len-- > 0)
			dst[new_len] = str[start + new_len];
	}
	return (dst);
}

