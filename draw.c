/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/11 17:53:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_vector3D	load_vector(int i, int j, int k)
{
	t_vector3D	v;

	v.x = (float)i;
	v.y = (float)j;
	v.z = (float)k;
	return (v);
}

static void	draw_dots(t_FdF_info *fdf)
{
	int			i;
	int			j;
	t_map		*map;
	t_vector2D	v;
	t_vector3D	v3;

	i = 0;
	j = 0;
	map = fdf->map;
	ft_printf("MAP x: %d, y: %d\n", map->map_size_x, map->map_size_y);
	while (j < map->map_size_y - 1)
	{
		while (i < map->map_size_x)
		{
			v3 = load_vector(i, j, -map->map[j][i].pixel);
			v = get_iso_perspective(v3, map);
			printf("Vector x: %f y: %f\n", v.x, v.y);
			mlx_put_pixel(fdf->img, HEIGHT / 2 + v.x, HEIGHT / 2 + v.y, 0xFF0000FF);
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
