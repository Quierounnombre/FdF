/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:48:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 14:49:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

static void	zoom_out(t_FdF_info *fdf)
{
	if ((int)fdf->cam->dim.x > 0.5f && (int)fdf->cam->dim.y > 0.5f)
	{
		fdf->cam->dim.x -= 0.1f;
		fdf->cam->dim.y -= 0.1f;
	}
	set_dark(fdf);
	draw(fdf);
}

static void	zoom_in(t_FdF_info *fdf)
{
	if ((int)fdf->cam->dim.x < (INT_MAX - 1)
		&& (int)fdf->cam->dim.y < (INT_MAX - 1))
	{
		fdf->cam->dim.x += 0.1f;
		fdf->cam->dim.y += 0.1f;
	}
	set_dark(fdf);
	draw(fdf);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_FdF_info	*fdf;

	fdf = param;
	if (ydelta > 0)
		zoom_in(fdf);
	else if (ydelta < 0)
		zoom_out(fdf);
	if (xdelta)
		ft_printf("sry, pero no soporto este tipo de movimiento :,(\n");
	ft_printf("Zoom actual (%d, %d)\n", (int)fdf->cam->dim.x,
		(int)fdf->cam->dim.y);
}
