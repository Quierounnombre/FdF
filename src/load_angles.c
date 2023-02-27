/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_angles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:41:12 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 14:47:19 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	load_angles(t_angle *ang, t_dir_vectors *v)
{
	v->v_alpha.x = cos(ang->alpha);
	v->v_alpha.y = sin(ang->alpha);
	ft_printf("V_alpha (%d) x: %d y: %d\n",
		(int)ang->alpha, (int)v->v_alpha.x, (int)v->v_alpha.y);
	v->v_beta.x = cos(ang->beta);
	v->v_beta.y = sin(ang->beta);
	ft_printf("V_beta (%d) x: %d y: %d\n",
		(int)ang->beta, (int)v->v_beta.x, (int)v->v_beta.y);
	v->v_gamma.x = cos(ang->gamma);
	v->v_gamma.y = sin(ang->gamma);
	ft_printf("V_gamma (%d) x: %d y: %d\n",
		(int)ang->gamma, (int)v->v_gamma.x, (int)v->v_gamma.y);
	ft_printf("--------------------\nAngulo iso terminado\n");
	ft_printf("--------------------\n");
}
