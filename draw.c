/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/14 17:12:18 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_vector2D	draw_dot(t_FdF_info *fdf, int i, int j)
{
	t_vector2D	v;
	t_vector3D	v3;
	t_map		*map;

	map = fdf->map;
	v3 = load_vector3d(i, j, -map->map[j][i].pixel);
	v = get_iso_perspective(v3, fdf);
	printf("Vect2D: %f | %f\n", v.x, v.y);
	mlx_put_pixel(fdf->img, WIDTH / 6 + v.x, HEIGHT / 2 + v.y, 0xFF0000FF);
	return (v);
}

static void	draw_dots(t_FdF_info *fdf)
{
	int			i;
	int			j;
	t_map		*map;
	t_vector2D	v;

	i = 0;
	j = 0;
	map = fdf->map;
	ft_printf("MAP x: %d, y: %d\n", map->map_size_x, map->map_size_y);
	while (j < map->map_size_y - 1)
	{
		while (i < map->map_size_x)
		{
			v = draw_dot(fdf, i, j);
			draw_lines(fdf, i, j, v);
			i++;
		}
		j++;
		i = 0;
	}
}

void	draw(t_FdF_info *fdf)
{
	draw_dots(fdf);
	ft_printf("\n--------TERMINE DE DIBUJAR--------\n\n");
}
