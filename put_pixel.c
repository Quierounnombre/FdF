/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:38:43 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 18:50:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	put_pixel(t_img *img, int pos_x, int pos_y, int color)
{
	char	*pxl;
	size_t	move_pxl;

	move_pxl = (pos_y * img->line_length + pos_x * (img->bits_per_pixel >> 3));
	pxl = img->start + move_pxl;
	*pxl = color;
}
