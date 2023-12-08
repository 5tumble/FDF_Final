/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:38:03 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/08 15:25:14 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_check(t_pixel p1)
{
	int	color;

	if (p1.z == 0)
		color = 0x3a1c71;
	else if (p1.z > 0 && p1.z < 40)
		color = 0xd76d77;
	else if (p1.z >= 40)
		color = 0xffaf7b;
	else if (p1.z < 0 && p1.z > -40)
		color = 0xffd460;
	else
		color = 0x05dfd7;
	return (color);
}

t_pixel	project_2d(t_pixel p)
{
	t_pixel	new_p;

	new_p.x = (p.x - p.y) * cos(0.5);
	new_p.y = (p.x + p.y) * sin(0.5) - p.z;
	return (new_p);
}

t_draw	*init_draw(t_pixel p1, t_pixel p2)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	if (!draw)
		exit (1);
	draw->absx = abs(p2.x - p1.x);
	draw->absy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		draw->relx = 1;
	else
		draw->relx = -1;
	if (p1.y < p2.y)
		draw->rely = 1;
	else
		draw->rely = -1;
	draw->err = draw->absx - draw->absy;
	return (draw);
}

void	my_mlx_pixel_put(t_data *data, t_pixel p)
{
	char	*dst;

	dst = data->addr + ((p.y + 200) * data->line_len + (p.x + 1750)
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = p.color;
}

void	draw_line(t_pixel p1, t_pixel p2, t_data *data, t_fdf *fdf)
{
	t_draw	*draw;
	t_pixel	iso_p1;
	t_pixel	iso_p2;

	p1.z = fdf->matrix[p1.y][p1.x];
	p2.z = fdf->matrix[p2.y][p2.x];
	p1.x *= data->zoom / fdf->x;
	p1.y *= data->zoom / fdf->x;
	p2.x *= data->zoom / fdf->x;
	p2.y *= data->zoom / fdf->x;
	iso_p1 = project_2d(p1);
	iso_p2 = project_2d(p2);
	iso_p1.z = p1.z;
	iso_p2.z = p2.z;
	draw = init_draw(iso_p1, iso_p2);
	iso_p1.color = color_check(p1);
	draw_pix(iso_p1, iso_p2, data, draw);
	free(draw);
}
