/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/01/27 19:33:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_struct(t_FdF_info *fdf)
{
	free_map(fdf->map);
	free(fdf->map);
	mlx_terminate(fdf->mlx);
	free(fdf->img);
	free(fdf);
}
