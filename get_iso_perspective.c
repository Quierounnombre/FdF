/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iso_perspective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/09 17:45:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	load_vectors(t_vector2D *v_0, t_vector2D *v_120, t_vector2D *v_240)
{
	v_0->x = cos(0);
	v_0->y = sin(0);
	printf("V_0 x: %f y: %f\n", v_0->x, v_0->y);
	v_120->x = cos(120);
	v_120->y = sin(120);
	printf("V_120 x: %f y: %f\n", v_120->x, v_120->y);
	v_240->x = cos(240);
	v_240->y = sin(240);
	printf("V_240 x: %f y: %f\n", v_240->x, v_240->y);
}

t_vector2D	get_iso_perspective(int i, int j, int k)
{
	static t_vector2D	v_0;
	static t_vector2D	v_120;
	static t_vector2D	v_240;
	t_vector2D			v_r;

	if (v_0.x != 1)
		load_vectors(&v_0, &v_120, &v_240);
	v_r.x = (v_0.x * i) + (v_120.x * j) + (v_240.x * k);
	v_r.y = (v_0.y * i) + (v_120.y * j) + (v_240.y * k);
	return (v_r);
}
