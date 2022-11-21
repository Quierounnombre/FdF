/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:44:32 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/21 17:54:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while ((i + 1) != map->map_size_y)
	{
		free(map->map[i]);
		i++;
	}
	free (map->map);
}
