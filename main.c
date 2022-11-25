/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 19:10:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	t_FdF_info	*fdf;

	if (init(argc, argv, &fdf))
	{
		new_img(100, 100, &fdf->img);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
		mlx_loop(fdf->mlx);
	}
	system("leaks FdF");
}
