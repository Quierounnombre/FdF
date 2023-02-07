/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/07 17:19:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	hook(void	*param)
{
	t_FdF_info	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("HEY\n");
		close_fdf(fdf);
		ft_printf("HEY\n");
	}
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_loop_hook(fdf->mlx, hook, fdf);
	mlx_close_hook(fdf->mlx, close_fdf, fdf);
}

