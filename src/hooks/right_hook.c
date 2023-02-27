/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 15:57:50 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	right_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->ang->alpha != (INT_MIN + 1)
		&& (int)fdf->cam->ang->beta != (INT_MIN + 1))
	{
		fdf->cam->ang->alpha -= 0.1f;
		fdf->cam->ang->beta -= 0.1f;
		load_angles(fdf->cam->ang, fdf->cam->dir_vec);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo superar el limite de los ints\n");
}
