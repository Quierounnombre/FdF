/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:41:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/01 17:08:30y vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	color_gradient(t_map *map, t_vector3D v3,
	uint32_t *color_offset, uint32_t *color_init)
{
	uint32_t	color_end;

	color_end = map->map[(int)v3.y][(int)v3.x].color;
	if (color_end > *color_init)
	{
		*color_offset = color_end - *color_init;
		return (true);
	}
	*color_offset = -(*color_init - color_end);
	*color_init = color_end;
	return (false);
}

static int	calc_n_dots(float *x_offset, float *y_offset, uint32_t *color)
{
	int	n_dots;

	n_dots = sqrt(pow(*x_offset, 2) + pow(*y_offset, 2));
	*x_offset /= n_dots;
	*y_offset /= n_dots;
	*color /= n_dots;
	return (n_dots);
}

static void	draw_line(t_FdF_info *fdf, t_vector3D v3, t_vector2D v_init,
				uint32_t color)
{
	t_vector2D	v_end;
	t_vector2D	v_offset;
	t_bool		color_flag;
	float		n_dots;
	uint32_t	color_offset;

	v_end = get_iso_perspective(v3, fdf);
	color_flag = color_gradient(fdf->map, v3, &color_offset, &color);
	v_offset.x = v_end.x - v_init.x;
	v_offset.y = v_end.y - v_init.y;
	n_dots = calc_n_dots(&v_offset.x, &v_offset.y, &color_offset);
	while (n_dots > 0)
	{
		if (v_init.x >= 0 && v_init.x < WIDTH && v_init.y >= 0 && v_init.y
			< HEIGHT)
			mlx_put_pixel(fdf->img, v_init.x, v_init.y, color);
		v_init.x += v_offset.x;
		v_init.y += v_offset.y;
		if (color_flag)
			color += color_offset;
		else
			color -= color_offset;
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
