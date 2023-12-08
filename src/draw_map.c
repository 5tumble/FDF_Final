/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:38:00 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:25 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_closing_line(int x, t_data *data, t_fdf *fdf)
{
	int	y;

	y = 0;
	while (y <= fdf->y - 1)
	{
		draw_line((t_pixel){x, y, 0x19b521, 1},
			(t_pixel){x, y + 1, 0x19b521, 1}, data, fdf);
		y++;
	}
}

void	draw_map(t_fdf *fdf, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= fdf->y)
	{
		x = 0;
		while (x < fdf->x - 1)
		{
			if (x < fdf->x)
				draw_line((t_pixel){x, y, 0x19b521, 1},
					(t_pixel){x + 1, y, 0x19b521, 1}, data, fdf);
			if (y < fdf->y)
				draw_line((t_pixel){x, y, 0x19b521, 1},
					(t_pixel){x, y + 1, 0x19b521, 1}, data, fdf);
			x++;
		}
		y++;
	}
	draw_closing_line(x, data, fdf);
}
