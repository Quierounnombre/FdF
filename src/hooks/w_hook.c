/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:41:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:15:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	w_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->pos.y > (INT_MIN + (HEIGHT / 100)))
	{
		fdf->cam->pos.y -= (HEIGHT / 100);
		ft_printf("Posición actual de la camara (%d, %d)\n",
			(int)fdf->cam->pos.x, (int)fdf->cam->pos.y);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
