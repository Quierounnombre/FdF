/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:54:55 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:15:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	space_hook(t_FdF_info *fdf)
{
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	select_perspective(fdf);
	set_dimensions(fdf->map);
	load_angles(fdf->cam->ang, fdf->cam->dir_vec);
	fdf->cam->pos.x = 0;
	fdf->cam->pos.y = 0;
	fdf->cam->dim = set_dimensions(fdf->map);
	draw(fdf);
}
