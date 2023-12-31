/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:17:09 by rukoltso          #+#    #+#             */
/*   Updated: 2023/01/11 12:25:02 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	if ((n >= 48 && n <= 57)
		|| (n >= 65 && n <= 90)
		|| (n >= 97 && n <= 122))
		return (n);
	return (0);
}
