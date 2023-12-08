/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:40:57 by rukoltso          #+#    #+#             */
/*   Updated: 2023/11/06 14:28:10 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*rtn;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	rtn = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, len_s1 + 1);
	ft_strlcpy((rtn + len_s1), s2, len_s2 + 1);
	free(s1);
	return (rtn);
}
