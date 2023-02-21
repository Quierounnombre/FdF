/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:32 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/21 18:01:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vector3D	set_dimensions(t_map *map)
{
	t_vector3D	result;
	float		cut_correct;

	cut_correct = 1;
	printf("Map %d | %d\n", map->map_size_x, map->map_size_y);
	result.x = ((HEIGHT + WIDTH) * 3)
		/ (map->map_size_x * (map->map_size_y - 1));
	if (!result.x)
		result.x = 1;
	result.y = result.x;
	result.z = 1;
	printf("Zoom: %f\n", result.x);
	printf("Escala de z: %f\n", result.z);
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented