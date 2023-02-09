/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/09 14:39:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	init_map(t_map *map);

t_FdF_info	*init_struct(void)
{
	t_FdF_info	*struk;
	t_map		*map;

	struk = (t_FdF_info *) malloc(sizeof(t_FdF_info));
	if (struk)
	{
		map = (t_map *) malloc(sizeof(t_map));
		if (map)
		{
			struk->map = map;
			init_map(struk->map);
			if (struk->map->map)
				return (struk);
			free(map);
		}
		free(struk);
	}
	return (struk);
}

static void	init_map(t_map *map)
{
	map->map = (t_pixel **) malloc (sizeof(t_pixel *));
	if (map->map)
	{
		map->map_size_y = 1;
		map->map_size_x = 0;
	}
}
