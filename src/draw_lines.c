/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:41:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/23 16:34:50 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	draw_line(t_FdF_info *fdf, t_vector3D v3, t_vector2D v_init,
				uint32_t init_color)
{
	t_vector2D	v_end;
	float		x_offset;
	float		y_offset;
	float		n_dots;

	v_end = get_iso_perspective(v3, fdf);
	x_offset = v_end.x - v_init.x;
	y_offset = v_end.y - v_init.y;
	n_dots = sqrt(pow(x_offset, 2) + pow(y_offset, 2));
	x_offset /= n_dots;
	y_offset /= n_dots;
	while (n_dots > 0)
	{
		if (v_init.x >= 0 && v_init.x < WIDTH && v_init.y >= 0 && v_init.y
			< HEIGHT)
			mlx_put_pixel(fdf->img, v_init.x, v_init.y, init_color);
		v_init.x += x_offset;
		v_init.y += y_offset;
		n_dots--;
	}
}

void	draw_lines(t_FdF_info *fdf, int i, int j, t_vector2D v)
{
	t_map		*map;

	map = fdf->map;
	if ((map->map_size_y - 1) > (j + 1))
		draw_line(fdf, load_vector3d(i, j + 1, map->map[j + 1][i].pixel), v,
			map->map[j][i].color);
	if (map->map_size_x > (i + 1))
		draw_line(fdf, load_vector3d(i + 1, j, map->map[j][i + 1].pixel), v,
			map->map[j][i].color);
}
