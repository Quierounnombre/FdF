/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:35 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 17:20:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**store_file(int fd)
{
	char	*s;
	char	**return_s;
	size_t	i;

	s = "Hola";
	i = 0;
	return_s[i] = (char *)ft_calloc(1, sizeof(char *));
	while (s)
	{
		s = ft_get_next_line(fd);
		if (s)
		{
			return_s[i] = s;
			i++;
			return_s[i] = (char *)ft_calloc(1, sizeof(char *));
			free(s);
		}
	}
	return (return_s);
}
