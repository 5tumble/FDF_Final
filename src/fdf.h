/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:57 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:45:10 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_draw
{
	int	absx;
	int	absy;
	int	relx;
	int	rely;
	int	err;
	int	e2;
}		t_draw;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}		t_mlx;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
	int	z;

}		t_pixel;

typedef struct s_fdf
{
	int	x;
	int	y;
	int	**matrix;
}		t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	float	zoom;
	int		color;
	int		window_x;
	int		window_y;
}			t_data;

t_draw	*init_draw(t_pixel p1, t_pixel p2);
void	my_mlx_pixel_put(t_data *data, t_pixel p);
void	draw_line(t_pixel p1, t_pixel p2, t_data *data, t_fdf *fdf);

int		ft_count_nb(char *line, char sep);
void	read_map(char *file_name, t_fdf *fdf);
void	fill_matrix(int *i_line, char *line);
void	get_dimensions(char *file_name, t_fdf *fdf);

void	print_map(char *file_name);
void	print_matrix(t_fdf *fdf);

void	free_array(int **arr, int len);

void	draw_map(t_fdf *fdf, t_data *data);

int		close_window(t_mlx *x);

int		close_window_key(int keycode, t_mlx *x);

void	scale_z(t_fdf *fdf);

void	draw_pix(t_pixel iso_p1, t_pixel iso_p2, t_data *data, t_draw *draw);
void	data_init(t_data *data);
void	init_mlx(t_data *data, t_fdf *fdf);

void	free_matrix(t_fdf *fdf);

#endif
