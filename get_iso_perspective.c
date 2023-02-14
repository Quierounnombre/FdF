/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iso_perspective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/14 16:58:35 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vector2D	get_iso_perspective(t_vector3D v3, t_FdF_info *fdf)
{
	t_vector2D		v_r;
	t_cam			*cam;
	t_dir_vectors	*v_d;

	cam = fdf->cam;
	v_d = cam->dir_vec;
	v_r.x = (v_d->v_alpha.x * v3.x * cam->dim.x)
		+ (v_d->v_beta.x * v3.y * cam->dim.y)
		+ (v_d->v_gamma.x * v3.z * cam->dim.z);
	v_r.y = (v_d->v_alpha.y * v3.x * cam->dim.x)
		+ (v_d->v_beta.y * v3.y * cam->dim.y)
		+ (v_d->v_gamma.y * v3.z * cam->dim.z);
	return (v_r);
}
