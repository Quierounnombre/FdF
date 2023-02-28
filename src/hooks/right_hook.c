/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/28 16:15:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	right_hook(t_FdF_info *fdf)
{
	if (fdf->cam->perps->current < 1)
		fdf->cam->perps->current = 6;
	fdf->cam->perps->current--;
	select_perspective(fdf);
	load_angles(fdf->cam->ang, fdf->cam->dir_vec);
	set_dark(fdf);
	draw(fdf);
	usleep(100000);
}
