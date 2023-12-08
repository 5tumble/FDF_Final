/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:36 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:21 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multiply_z(int factor, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i <= fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->matrix[i][j] *= factor;
			j++;
		}
		i++;
	}
}

void	check_max(int max, t_fdf *fdf)
{
	if (max <= 4)
		multiply_z(25, fdf);
	else if (max > 4 && max <= 10)
		multiply_z(10, fdf);
	else if (max > 10 && max <= 25)
		multiply_z(7, fdf);
	else if (max > 25 && max <= 40)
		multiply_z(5, fdf);
	else if (max > 40 && max <= 60)
		multiply_z(3, fdf);
}

void	scale_z(t_fdf *fdf)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = fdf->matrix[0][0];
	while (i <= fdf->y)
	{
		j = 0;
		while (j < fdf->x - 1)
		{
			if (max < fdf->matrix[i][j])
				max = fdf->matrix[i][j];
			j++;
		}
		i++;
	}
	check_max(max, fdf);
}
