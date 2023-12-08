/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:54 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:24 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= fdf->y)
	{
		free(fdf->matrix[i]);
		i++;
	}
	free(fdf->matrix);
	free(fdf);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_data	data;

	if (ac != 2)
		exit (1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (1);
	read_map(av[1], fdf);
	scale_z(fdf);
	data_init(&data);
	init_mlx(&data, fdf);
}
