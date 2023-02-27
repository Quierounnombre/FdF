/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:52:37 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 15:54:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	left_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->ang->alpha != (INT_MAX - 1)
		&& (int)fdf->cam->ang->beta != (INT_MAX - 1))
	{
		fdf->cam->ang->alpha += 0.1f;
		fdf->cam->ang->beta += 0.1f;
		load_angles(fdf->cam->ang, fdf->cam->dir_vec);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo superar el limite de los ints\n");
}
