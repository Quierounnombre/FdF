/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iso_perspective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/13 17:35:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_vector3D	set_dimensions(t_map *map)
{
	t_vector3D	result;
	int			cut_correct;

	cut_correct = map->map_size_x + 1;
	result.x = (float)(WIDTH) / (float)(1 * (map->map_size_x + cut_correct));
	result.y = (float)(HEIGHT) / (float)(1 * (map->map_size_y + cut_correct));
	result.z = 5;
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented

static void	load_vectors(t_vector2D *v_0, t_vector2D *v_120, t_vector2D *v_240)
{
	v_0->x = cos(0);
	v_0->y = sin(0);
	printf("V_0 x: %f y: %f\n", v_0->x, v_0->y);
	v_120->x = cos(120);
	v_120->y = sin(120);
	printf("V_120 x: %f y: %f\n", v_120->x, v_120->y);
	v_240->x = cos(240);
	v_240->y = sin(240);
	printf("V_240 x: %f y: %f\n", v_240->x, v_240->y);
	printf("--------------------\nAngulo iso terminado\n--------------------\n");
}

t_vector2D	get_iso_perspective(t_vector3D v3, t_map *map)
{
	static t_vector2D	v_0;
	static t_vector2D	v_120;
	static t_vector2D	v_240;
	static t_vector3D	dim;
	t_vector2D			v_r;

	if (v_0.x != 1)
	{
		dim = set_dimensions(map);
		load_vectors(&v_0, &v_120, &v_240);
	}
	v_r.x = (v_0.x * v3.x * dim.x) + (v_120.x * v3.y * dim.y)
		+ (v_240.x * v3.z * dim.z);
	v_r.y = (v_0.y * v3.x * dim.x) + (v_120.y * v3.y * dim.y)
		+ (v_240.y * v3.z * dim.z);
	return (v_r);
}
