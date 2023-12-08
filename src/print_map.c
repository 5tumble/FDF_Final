/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:51 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:23 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	print_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i <= fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			ft_printf("%i ", fdf->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
