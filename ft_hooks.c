/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/07 20:44:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	key_hook(void	*param)
{
	t_FdF_info	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_loop_hook(fdf->mlx, key_hook, fdf);
	mlx_close_hook(fdf->mlx, close_fdf, fdf);
}

