/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:35 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/21 16:57:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_bool	store_file(int fd, t_map *map)
{
	char	*s;
	size_t	len;
	int		line;

	s = "Hola";
	len = 0;
	line = 0;
	while (s)
	{
		s = ft_get_next_line(fd);
		if (s)
		{
			if (store_line(s, map, line))
				line++;
			else
				return (false);
		}
	}
	return (true);
}
