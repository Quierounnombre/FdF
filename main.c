/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 17:57:37 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_FdF_info	*fdf;

	if (init(argc, argv, &fdf))
	{
		fdf->mlx = mlx_init();
		if (fdf->mlx)
		{
			fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
			fdf->img->img = mlx_new_image(fdf->img, 1000, 1000);
			fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
			my_mlx_pixel_put(fdf->img, 500, 500, 0x00FF0000);
			my_mlx_pixel_put(fdf->img, 501, 500, 0x00FF0000);
			my_mlx_pixel_put(fdf->img, 500, 501, 0x00FF0000);
			my_mlx_pixel_put(fdf->img, 501, 501, 0x00FF0000);
			mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
			mlx_loop(fdf->mlx);
		}
		system("leaks FdF");
	}
}
