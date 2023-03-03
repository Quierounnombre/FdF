/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:39:23 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:14:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	k_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->ang->gamma > (INT_MIN + 1))
	{
		fdf->cam->ang->gamma -= 0.1f;
		load_angles(fdf->cam->ang, fdf->cam->dir_vec);
		draw(fdf);
	}
	else
		ft_printf("No puedo superar el limite de los ints\n");
}
