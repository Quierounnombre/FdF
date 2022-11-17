/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:35 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 16:13:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**store_file(int fd)
{
	char	*s;
	char	*temp_s;
	char	**return_s;
	int		i;

	s = " ";
	while (s)
	{
		s = ft_get_next_line(fd);
		temp_s = ft_strjoin(temp_s, s);
		if (s)
			free(s);
	}
	return_s = ft_split(temp_s, '\n');
	if (temp_s)
		free(temp_s);
	return (return_s);
}
