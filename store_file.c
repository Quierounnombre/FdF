/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:35 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/18 14:25:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**store_file(int fd)
{
	char	*s;
	size_t	i;

	s = "Hola";
	i = 0;
	while (s)
	{
		s = ft_get_next_line(fd);
		if (s)
		{
			ft_printf("%s", s);
			/*return_s[i] = s;
			i++;
			return_s[i] = (char *)ft_calloc(1, sizeof(char *));*/
			free(s);
		}
	}
	return (NULL);
}
