/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/08 14:18:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	set_dimensions(int n_dots, int dimension)
{
	int	result;
	int	cut_correction;

	cut_correction = 1;
	result = dimension / (n_dots + cut_correction);
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented

static void	draw_dots(int x_dim, int y_dim, t_FdF_info *fdf)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = 0;
	j = 0;
	x_pos = x_dim;
	y_pos = y_dim;
	while (j != fdf->map->map_size_y)
	{
		while (i != fdf->map->map_size_x)
		{
			mlx_put_pixel(fdf->img, x_pos, y_pos, 0xFF0000FF);
			i++;
			x_pos = (x_dim) + (x_dim * i);
		}
		y_pos = (y_dim) + (y_dim * j);
		i = 0;
		j++;
	}
}

void	draw(t_FdF_info *fdf)
{
	int	x_dimension;
	int	y_dimension;

	x_dimension = set_dimensions(fdf->map->map_size_x, WIDTH);
	y_dimension = set_dimensions(fdf->map->map_size_y, HEIGHT);
	printf("\nx dim == %d\n", x_dimension);
	printf("\ny dim == %d\n", y_dimension);
	draw_dots(x_dimension, y_dimension, fdf);
}
