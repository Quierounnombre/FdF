/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:52:03 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 19:09:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	new_img(int size_x, int size_y, t_img **img)
{
	(*img)->img = mlx_new_image((*img), size_x, size_y);
	(*img)->start = mlx_get_data_addr(&(*img)->img, &(*img)->bits_per_pixel,
			&(*img)->line_length, &(*img)->endian);
}
