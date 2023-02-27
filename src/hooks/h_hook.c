/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:53 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 15:51:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	h_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->ang->alpha != (INT_MIN + 1))
	{
		fdf->cam->ang->alpha -= 0.1f;
		load_angles(fdf->cam->ang, fdf->cam->dir_vec);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo superar el limite de los ints\n");
}
