/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:32 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vector3D	set_dimensions(t_map *map)
{
	t_vector3D	result;
	float		cut_correct;

	cut_correct = 1;
	ft_printf("Map %d | %d\n", map->map_size_x, map->map_size_y - 1);
	result.x = ((HEIGHT + WIDTH) * 3)
		/ (map->map_size_x * (map->map_size_y - 1));
	if (!result.x)
		result.x = 2.5;
	else if (result.x > 100)
		result.x = 100;
	result.y = result.x;
	result.z = 1;
	ft_printf("Zoom: %d\n", (int)result.x);
	ft_printf("Escala de z: %d\n", (int)result.z);
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented