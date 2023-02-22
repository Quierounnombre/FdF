/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:04 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:29:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	set_dark(t_FdF_info *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != HEIGHT)
	{
		while (i != WIDTH)
		{
			mlx_put_pixel(fdf->img, i, j, 0x000000FF);
			i++;
		}
		i = 0;
		j++;
	}
}
