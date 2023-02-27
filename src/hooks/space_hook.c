/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:54:55 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 15:59:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	space_hook(t_FdF_info *fdf)
{
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fdf->cam->ang->alpha = 0;
	fdf->cam->ang->beta = 2.094395;
	fdf->cam->ang->gamma = 4.18880;
	load_angles(fdf->cam->ang, fdf->cam->dir_vec);
	set_dimensions(fdf->map);
	fdf->cam->pos.x = 0;
	fdf->cam->pos.y = 0;
	set_dark(fdf);
	draw(fdf);
}
