/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:52:16 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/04 16:01:14 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char *mem;

	len = ft_strlen(s) + 1;
	mem = malloc(sizeof(char) * len);
	if (!mem)
		return (mem);
	mem = ft_memcpy(mem, s, len);
	return (mem);
}
