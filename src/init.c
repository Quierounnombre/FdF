/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:05:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:44:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	set_mlx(void)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx_set_setting(MLX_FULLSCREEN, false);
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_set_setting(MLX_DECORATED, true);
	mlx_set_setting(MLX_HEADLESS, false);
}

static t_bool	ft_mlx_start(t_FdF_info **fdf)
{
	set_mlx();
	(*fdf)->mlx = mlx_init(WIDTH, HEIGHT, NAME, false);
	if ((*fdf)->mlx)
	{
		(*fdf)->img = mlx_new_image((*fdf)->mlx, WIDTH, HEIGHT);
		if ((*fdf)->img)
		{
			if (!(mlx_image_to_window((*fdf)->mlx, (*fdf)->img, 0, 0) > 0))
				return (true);
		}
	}
	return (false);
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
			if (fdf && store_file(fd, (*fdf)->map))
			{
				close(fd);
				fd = 0;
				(*fdf)->cam->dim = set_dimensions((*fdf)->map);
				if (ft_mlx_start(fdf))
					return (true);
			}
			free_struct(*fdf);
			if (fd)
				close (fd);
			return (false);
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d\n\n", argv[1], fd);
	}
	return (false);
}
