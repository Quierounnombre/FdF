/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:21:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/28 18:26:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	a_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->pos.x != (INT_MIN + (WIDTH / 100)))
	{
		fdf->cam->pos.x -= (WIDTH / 100);
		ft_printf("Posición actual de la camara (%d, %d)\n",
			(int)fdf->cam->pos.x, (int)fdf->cam->pos.y);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
