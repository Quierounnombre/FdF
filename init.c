/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:05:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/01/26 20:47:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	set_mlx(void)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx_set_setting(MLX_FULLSCREEN, false);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_set_setting(MLX_DECORATED, false);
	mlx_set_setting(MLX_HEADLESS, false);
}

t_bool	init(int argc, char **argv, t_FdF_info **fdf)
{
	int	fd;

	if (parse(argc, argv))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			*fdf = init_struct();
			if (store_file(fd, (*fdf)->map))
			{
				set_mlx();
				(*fdf)->mlx = mlx_init(X_SIZE, Y_SIZE, NAME, false);
				if ((*fdf)->mlx)
					return (true);
			}
			free_struct(*fdf);
			close (fd);
			return (false);
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d", argv[1], fd);
	}
	return (false);
}
