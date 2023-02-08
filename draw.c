/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/08 18:26:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static float	set_dimensions(int n_dots, int dimension)
{
	float	result;
	int		cut_correction;

	cut_correction = 1;
	result = (float)dimension / (float)(n_dots + cut_correction);
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented

static void	draw_dots(float x_dim, float y_dim, t_FdF_info *fdf)
{
	int		i;
	int		j;
	float	x_pos;
	float	y_pos;
	t_map	*map;

	i = 0;
	j = 0;
	x_pos = x_dim;
	y_pos = y_dim;
	map = fdf->map;
	while (j != map->map_size_y)
	{
		while (i != map->map_size_x)
		{
			mlx_put_pixel(fdf->img, x_pos, y_pos, 0xFF0000FF);
			i++;
			x_pos = ((x_dim) + (x_dim * i));
		}
		j++;
		y_pos = (y_dim) + (y_dim * j);
		x_pos = x_dim;
		i = 0;
	}
}

void	draw(t_FdF_info *fdf)
{
	float	x_dimension;
	float	y_dimension;

	x_dimension = set_dimensions(fdf->map->map_size_x, WIDTH);
	y_dimension = set_dimensions(fdf->map->map_size_y, HEIGHT);
	draw_dots(x_dimension, y_dimension, fdf);
}
