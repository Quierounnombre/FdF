/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:52:37 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:14:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	left_hook(t_FdF_info *fdf)
{
	if (fdf->cam->perps->current > 4)
		fdf->cam->perps->current = 0;
	fdf->cam->perps->current++;
	select_perspective(fdf);
	load_angles(fdf->cam->ang, fdf->cam->dir_vec);
	draw(fdf);
	usleep(100000);
}
