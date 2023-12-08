/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:38:06 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:27 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_mlx *x)
{
	mlx_destroy_window(x->mlx, x->window);
	mlx_destroy_display(x->mlx);
	free(x->mlx);
	exit (0);
}

int	close_window_key(int keycode, t_mlx *x)
{
	if (keycode == 65307)
		close_window(x);
	return (0);
}
