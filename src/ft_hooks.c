/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:52:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	key_hook(void	*param)
{
	t_FdF_info	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		a_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		d_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		w_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		s_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		z_hook(fdf);
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_loop_hook(fdf->mlx, key_hook, fdf);
	mlx_close_hook(fdf->mlx, close_fdf, fdf);
}
