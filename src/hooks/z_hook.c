/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:49:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	z_hook(t_FdF_info *fdf)
{
	if ((int)fdf->cam->dim.z > (INT_MIN + 1))
	{
		fdf->cam->dim.z -= 0.1f;
		ft_printf("Valor de la cota: %d\n", (int)fdf->cam->dim.z);
		draw(fdf);
	}
	else
		ft_printf("No puedo pasarme del limite inferior de los ints\n");
}
