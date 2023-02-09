/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/09 17:37:01 by vicgarci         ###   ########.fr       */
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

static void	draw_dots(t_FdF_info *fdf)
{
	int			i;
	int			j;
	t_map		*map;
	t_vector2D	v;

	i = 0;
	j = 0;
	map = fdf->map;
	while (j < map->map_size_y - 1)
	{
		while (i < map->map_size_x)
		{
			v = get_iso_perspective(i, j, map->map[i][j].pixel);
			printf("Vector x: %f y: %f\n", v.x, v.y);
			mlx_put_pixel(fdf->img, v.x, v.y, 0xFF0000FF);
			i++;
		}
		j++;
		i = 0;
	}
}

void	draw(t_FdF_info *fdf)
{
	float	x_dimension;
	float	y_dimension;

	x_dimension = set_dimensions(fdf->map->map_size_x, WIDTH);
	y_dimension = set_dimensions(fdf->map->map_size_y, HEIGHT);
	draw_dots(fdf);
}
