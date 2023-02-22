/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:38:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:42:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	d_hook(t_FdF_info *fdf)
{
	if (fdf->cam->pos.x != (INT_MAX - 1))
	{
		fdf->cam->pos.x++;
		ft_printf("Posición actual de la camara (%d, %d)\n",
			(int)fdf->cam->pos.x, (int)fdf->cam->pos.y);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite superior de los ints\n");
}
