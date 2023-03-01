/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/01 15:07:25 by vicgarci         ###   ########.fr       */
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
	cam->perps->caballera.alpha = G_45;
	cam->perps->caballera.beta = G_180;
	cam->perps->caballera.gamma = G_225;
	cam->perps->dimetrica.alpha = 1.8326f;
	cam->perps->dimetrica.beta = 1.8326f;
	cam->perps->dimetrica.gamma = 2.61799f;
	cam->perps->trimetrica.alpha = 1.74533f;
	cam->perps->trimetrica.beta = cam->ang->alpha;
	cam->perps->trimetrica.gamma = 2.44346f;
	cam->perps->militar.alpha = 1.5708f;
	cam->perps->militar.beta = cam->ang->alpha;
	cam->perps->militar.gamma = 2.61799f;
}
/*---NOTAS----*/
/*La perspectiva caballera se realiza con los angulos de 45, 90 y 225
respectivamente, pero en este caso le he añadido 90º adicionales a beta
el eje YZ(si recuerdo bien) para que se endereze la imagen*/


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
