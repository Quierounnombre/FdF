/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:05:24 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 19:20:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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
				(*fdf)->mlx = mlx_init();
				if ((*fdf)->mlx)
				(*fdf)->win = mlx_new_window((*fdf)->mlx, 1000, 1000, "FDF");
				return (true);
			}
			else
				free_struct(*fdf);
			close (fd);
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d", argv[1], fd);
	}
	return (false);
}
