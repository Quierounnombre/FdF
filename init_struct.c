/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/20 15:57:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	init_map(t_FdF_info *struk, t_map *map)
{
	struk->map = map;
	map->map = (t_pixel **) malloc (sizeof(t_pixel *));
	if (map->map)
	{
		map->map_size_y = 1;
		map->map_size_x = 0;
	}
}

static t_bool	init_cam(t_cam *cam)
{
	cam->ang = (t_angle *)malloc(sizeof(t_angle));
	if (cam->ang)
	{
		cam->ang->alpha = 0;
		cam->ang->beta = 120;
		cam->ang->gamma = 240;
		cam->dir_vec = (t_dir_vectors *)malloc(sizeof(t_dir_vectors));
		if (cam->dir_vec)
		{
			load_angles(cam->ang, cam->dir_vec);
			return (true);
		}
		free(cam->ang);
	}
	return (false);
}

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
			init_map(struk, map);
			if (struk->map->map)
			{
				struk->cam = (t_cam *) malloc(sizeof(t_cam));
				if (struk->cam)
				{
					if (init_cam(struk->cam))
						return (struk);
				}
				free(struk->cam);
			}
			free(map);
		}
		free(struk);
	}
	return (struk);
}
