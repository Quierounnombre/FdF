/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/07 13:46:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	t_FdF_info	*fdf;

	if (init(argc, argv, &fdf))
	{
		ft_printf("%d\n", fdf->mlx->height);
		mlx_loop(fdf->mlx);
		free_struct(fdf);
	}
	system("leaks FdF");	
}
