/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:48:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/23 17:13:47 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

static void	zoom_out(t_FdF_info *fdf, int zoom_x, int zoom_y)
{
	if (fdf->cam->dim.x > 0.5f && fdf->cam->dim.y > 0.5f)
	{
		fdf->cam->dim.x -= 0.1f;
		fdf->cam->dim.y -= 0.1f;
		fdf->cam->pos.x += zoom_x;
		fdf->cam->pos.y += zoom_y;
	}
	set_dark(fdf);
	draw(fdf);
}

static void	zoom_in(t_FdF_info *fdf, int zoom_x, int zoom_y)
{
	if (fdf->cam->dim.x < (INT_MAX - 1) && fdf->cam->dim.y < (INT_MAX - 1))
	{
		fdf->cam->dim.x += 0.1f;
		fdf->cam->dim.y += 0.1f;
		fdf->cam->pos.x -= zoom_x;
		fdf->cam->pos.y -= zoom_y;
	}
	set_dark(fdf);
	draw(fdf);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_FdF_info	*fdf;
	int			zoom_x;
	int			zoom_y;

	zoom_x = WIDTH / 100;
	zoom_y = HEIGHT / 500;
	if (!zoom_x)
		zoom_x = 1;
	if (!zoom_y)
		zoom_y = 1;
	fdf = param;
	if (ydelta > 0)
		zoom_in(fdf, zoom_x, zoom_y);
	else if (ydelta < 0)
		zoom_out(fdf, zoom_x, zoom_y);
	if (xdelta)
		ft_printf("sry, pero no soporto este tipo de ratón :,(\n");
}
