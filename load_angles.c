/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_angles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:41:12 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/14 16:15:15 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	load_angles(t_angle *ang, t_dir_vectors *v)
{
	v->v_alpha.x = cos(ang->alpha);
	v->v_alpha.y = sin(ang->alpha);
	printf("V_alpha (%f) x: %f y: %f\n", ang->alpha, v->v_alpha.x, v->v_alpha.y);
	v->v_beta.x = cos(ang->beta);
	v->v_beta.y = sin(ang->beta);
	printf("V_beta (%f) x: %f y: %f\n", ang->beta, v->v_beta.x, v->v_beta.y);
	v->v_gamma.x = cos(ang->gamma);
	v->v_gamma.y = sin(ang->gamma);
	printf("V_gamma (%f) x: %f y: %f\n", ang->gamma, v->v_gamma.x, v->v_gamma.y);
	printf("--------------------\nAngulo iso terminado\n--------------------\n");
}
