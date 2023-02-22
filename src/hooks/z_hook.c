/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:49:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:52:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	z_hook(t_FdF_info *fdf)
{
	if (fdf->cam->dim.z != (INT_MIN + 1))
	{
		fdf->cam->dim.z--;
		ft_printf("Valor de la cota: %d\n", (int)fdf->cam->dim.z);
		set_dark(fdf);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
