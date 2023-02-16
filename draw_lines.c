/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:41:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	get_color_offset(t_vector3D color_pos, uint32_t init_color,
				t_map *map)
{
	int	offset;
	int	end;

	end = map->map[(int)color_pos.x][(int)color_pos.y].color;
	offset = end - init_color;
	if (offset)
	{
		ft_printf("\n-----------------------------------------------\n");
		ft_printf("OFFSET (%d, %d) -> %X\n\n", (int)color_pos.x, (int)color_pos.y, init_color);
		ft_printf("OFFSET (%d, %d) -> %X\n", (int)color_pos.x + 1, (int)color_pos.y, end);
		ft_printf("OFFSET (%d, %d) -> %X\n", (int)color_pos.x, (int)color_pos.y + 1, end);
	}
	return (offset);
}

static void	draw_line(t_FdF_info *fdf, t_vector3D v3, t_vector2D v_init,
				uint32_t init_color)
{
	t_vector2D	v_end;
	float		x_offset;
	float		y_offset;
	float		n_dots;
	int			color_offset;

	v_end = get_iso_perspective(v3, fdf);
	x_offset = v_end.x - v_init.x;
	y_offset = v_end.y - v_init.y;
	n_dots = sqrt(pow(x_offset, 2) + pow(y_offset, 2));
	color_offset = get_color_offset(v3, init_color, fdf->map);
	x_offset /= n_dots;
	y_offset /= n_dots;
	color_offset /= n_dots;
	while (n_dots > 0)
	{
		mlx_put_pixel(fdf->img, v_init.x, v_init.y, init_color);
		v_init.x += x_offset;
		v_init.y += y_offset;
		init_color += color_offset;
		n_dots--;
	}
}

void	draw_lines(t_FdF_info *fdf, int i, int j, t_vector2D v)
{
	t_map		*map;

	map = fdf->map;
	if ((map->map_size_y - 1) > (j + 1))
		draw_line(fdf, load_vector3d(i, j + 1, -map->map[j + 1][i].pixel), v,
			map->map[j][i].color);
	if (map->map_size_x > (i + 1))
		draw_line(fdf, load_vector3d(i + 1, j, -map->map[j][i + 1].pixel), v,
			map->map[j][i].color);
}
