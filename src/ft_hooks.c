/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/27 17:02:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	expand_hooks(t_FdF_info *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_U))
		u_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_K))
		k_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		i_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_J))
		j_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		left_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		right_hook(fdf);
}

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
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		x_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Y))
		y_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_H))
		h_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE))
		space_hook(fdf);
	expand_hooks(fdf);
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_loop_hook(fdf->mlx, key_hook, fdf);
	mlx_scroll_hook(fdf->mlx, scroll_hook, fdf);
	mlx_close_hook(fdf->mlx, close_fdf, fdf);
}
