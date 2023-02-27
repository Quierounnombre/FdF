/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iso_perspective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 17:51:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	ft_center_fdf(t_vector2D *v, t_FdF_info *fdf)
{
	static float	center_x;
	static float	center_y;

	if (!center_x)
	{
		center_x = (WIDTH / 2) - ((fdf->map->map_size_x / 2) * fdf->cam->dim.x);
		center_y = (HEIGHT / 2) - (((fdf->map->map_size_y - 1) / 2)
				* fdf->cam->dim.y);
	}
	v->x += center_x;
	v->y += center_y;
}

t_vector2D	get_iso_perspective(t_vector3D v3, t_FdF_info *fdf)
{
	t_vector2D		v_r;
	t_cam			*cam;
	t_dir_vectors	*v_d;

	cam = fdf->cam;
	v_d = cam->dir_vec;
	v_r.x = (v_d->v_alpha.x * v3.x * cam->dim.x)
		+ (v_d->v_beta.x * v3.y * cam->dim.y)
		+ (v_d->v_gamma.x * v3.z * cam->dim.z)
		+ cam->pos.x;
	v_r.y = (v_d->v_alpha.y * v3.x * cam->dim.x)
		+ (v_d->v_beta.y * v3.y * cam->dim.y)
		+ (v_d->v_gamma.y * v3.z * cam->dim.z)
		+ cam->pos.y;
	ft_center_fdf(&v_r, fdf);
	return (v_r);
}
