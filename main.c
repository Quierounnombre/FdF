/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 17:12:17 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**s;

	if (parse(argc, argv))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			s = store_file(fd);
			if (s)
			{
				ft_printf("%s", s[0]);
				ft_printf("%s", s[1]);
				ft_printf("%s", s[2]);
				while (*s)
					free(*(s++));
				free(s);
			}
			else
				ft_printf("He devuelto null");
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d", argv[1], fd);
	}
}
