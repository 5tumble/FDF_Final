/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:44 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:22 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pix(t_pixel iso_p1, t_pixel iso_p2, t_data *data, t_draw *draw)
{
	while (iso_p1.x != iso_p2.x || iso_p1.y != iso_p2.y)
	{
		my_mlx_pixel_put(data, iso_p1);
		draw->e2 = 2 * draw->err;
		if (draw->e2 > -draw->absy)
		{
			draw->err -= draw->absy;
			iso_p1.x += draw->relx;
		}
		if (draw->e2 < draw->absx)
		{
			draw->err += draw->absx;
			iso_p1.y += draw->rely;
		}
	}
}

void	data_init(t_data *data)
{
	data->window_x = 3500;
	data->window_y = 2000;
	data->zoom = 1300;
}

void	init_mlx(t_data *data, t_fdf *fdf)
{
	t_mlx	x;

	x.mlx = mlx_init();
	x.window = mlx_new_window(x.mlx, data->window_x, data->window_y, "FdF");
	data->img = mlx_new_image(x.mlx, data->window_x, data->window_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_len, &data->endian);
	draw_map(fdf, data);
	mlx_put_image_to_window(x.mlx, x.window, data->img, 0, 0);
	mlx_destroy_image(x.mlx, data->img);
	mlx_hook(x.window, 17, 0L, close_window, &x);
	mlx_key_hook(x.window, close_window_key, &x);
	free_matrix(fdf);
	mlx_loop(x.mlx);
}
