/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/07 17:21:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	close_fdf(void *param)
{
	t_FdF_info	*fdf;

	ft_printf("HAY\n");
	fdf = param;
	mlx_close_window(fdf->mlx);
	free_struct(fdf);
	ft_printf("HAY\n");
}
