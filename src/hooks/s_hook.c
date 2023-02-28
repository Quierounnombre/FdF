/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:45:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/28 18:28:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	s_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->pos.y != (INT_MAX - (HEIGHT / 100)))
	{
		fdf->cam->pos.y += (HEIGHT / 100);
		ft_printf("Posición actual de la camara (%d, %d)\n",
			(int)fdf->cam->pos.x, (int)fdf->cam->pos.y);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
