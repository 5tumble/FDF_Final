/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:48 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:22 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_nb(char *line, char sep)
{
	int	i;
	int	nb_count;

	i = 0;
	nb_count = 0;
	while (line[i])
	{
		while (line[i] && line[i] == sep)
			i++;
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			i++;
			nb_count++;
		}
		while (line[i] && line[i] != sep)
			i++;
	}
	return (nb_count);
}

char	*remove_newl(char *str)
{
	int		i;
	char	*strcpy;

	i = 0;
	if (!str)
		exit (0);
	strcpy = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\n')
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = '\0';
	free(str);
	return (strcpy);
}

void	get_dimensions(char *file_name, t_fdf *fdf)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_name, O_RDONLY);
	y = -1;
	line = get_next_line(fd);
	fdf->x = ft_count_nb(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	fdf->y = y;
}

void	fill_matrix(int *i_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		i_line[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums);
}

void	read_map(char *file_name, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	get_dimensions(file_name, fdf);
	fdf->matrix = (int **)malloc(sizeof(int *) * (fdf->y + 1));
	if (!fdf->matrix)
		exit (1);
	i = 0;
	while (i <= fdf->y)
		fdf->matrix[i++] = (int *)malloc(sizeof(int) * fdf->x);
	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = remove_newl(line);
		fill_matrix(fdf->matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
