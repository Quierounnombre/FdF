/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:43:40 by vicgarci         ###   ########.fr       */
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

static void	load_perspectives(t_cam *cam)
{
	cam->perps->isometrica.alpha = G_0;
	cam->perps->isometrica.beta = G_120;
	cam->perps->isometrica.gamma = G_240;
	cam->perps->current = 1;
	cam->perps->caballera.alpha = G_0;
	cam->perps->caballera.beta = G_45;
	cam->perps->caballera.gamma = -G_90;
	cam->perps->dimetrica.alpha = G_0;
	cam->perps->dimetrica.beta = G_125;
	cam->perps->dimetrica.gamma = -G_110;
	cam->perps->trimetrica.alpha = G_0;
	cam->perps->trimetrica.beta = G_100;
	cam->perps->trimetrica.gamma = G_220;
	cam->perps->militar.alpha = G_0;
	cam->perps->militar.beta = G_90;
	cam->perps->militar.gamma = G_225;
}

static t_bool	init_cam(t_cam *cam)
{
	cam->ang = (t_angle *)malloc(sizeof(t_angle));
	if (cam->ang)
	{
		cam->ang->alpha = G_0;
		cam->ang->beta = G_120;
		cam->ang->gamma = G_240;
		cam->pos.x = WIDTH / 10;
		cam->pos.y = 0;
		cam->dir_vec = (t_dir_vectors *)malloc(sizeof(t_dir_vectors));
		if (cam->dir_vec)
		{
			load_angles(cam->ang, cam->dir_vec);
			cam->perps = (t_perspective *)malloc(sizeof(t_perspective));
			if (cam->perps)
			{
				load_perspectives(cam);
				return (true);
			}
			free (cam->dir_vec);
		}
		free(cam->ang);
	}
	free(cam);
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
				free_map(map);
			}
			free(map);
		}
		free(struk);
	}
	return (struk);
}
