/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/28 16:10:35 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	select_perspective_load(t_angle *ang, t_angle new_ang)
{
	ang->alpha = new_ang.alpha;
	ang->beta = new_ang.beta;
	ang->gamma = new_ang.gamma;
}

void	select_perspective(t_FdF_info *fdf)
{
	if (fdf->cam->perps->current == 1)
	{
		select_perspective_load(fdf->cam->ang, fdf->cam->perps->isometrica);
		ft_printf("\n\n----VISTA ISOMETRICA----\n\n");
	}
	else if (fdf->cam->perps->current == 2)
	{
		select_perspective_load(fdf->cam->ang, fdf->cam->perps->dimetrica);
		ft_printf("\n\n----VISTA DIMETRICA----\n\n");
	}
	else if (fdf->cam->perps->current == 3)
	{
		select_perspective_load(fdf->cam->ang, fdf->cam->perps->trimetrica);
		ft_printf("\n\n----VISTA TRIMETRICA----\n\n");
	}
	else if (fdf->cam->perps->current == 4)
	{
		select_perspective_load(fdf->cam->ang, fdf->cam->perps->caballera);
		ft_printf("\n\n----VISTA CABALLERA----\n\n");
	}
	else
	{
		ft_printf("\n\n----VISTA MILTAR----\n\n");
		select_perspective_load(fdf->cam->ang, fdf->cam->perps->militar);
	}
}
