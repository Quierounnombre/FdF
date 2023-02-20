/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:32 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/20 16:44:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vector3D	set_dimensions(t_map *map)
{
	t_vector3D	result;
	float		cut_correct;

	cut_correct = 1;
	printf("Map %d | %d\n", map->map_size_x, map->map_size_y);
	result.x = (float)(WIDTH) / (float)((map->map_size_x + cut_correct) * 2);
	result.y = (float)(HEIGHT) / (float)(map->map_size_y * 2);
	result.z = 3;
	printf("Dimensión de x: %f\n", result.x);
	printf("Dimensión de y: %f\n", result.y);
	printf("Dimensión de z: %f\n", result.z);
	return (result);
}
//The cut correction, solve the amount of cuts needed to represent a line
//ex: a line of len 5 need, 6 cuts, a "." is a dot and a "-" a cut
// -.-.-.-.-.- this is how is should be represented