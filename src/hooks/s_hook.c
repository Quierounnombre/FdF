/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:45:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:45:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	s_hook(t_FdF_info *fdf)
{
	if (fdf->cam->pos.x != (INT_MAX - 1))
	{
		fdf->cam->pos.y++;
		ft_printf("Posición actual de la camara (%d, %d)\n",
			(int)fdf->cam->pos.x, (int)fdf->cam->pos.y);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
