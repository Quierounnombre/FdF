/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/18 18:48:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_FdF_info	*fdf_info;

	if (parse(argc, argv))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			fdf_info = init_struct();
			if (store_file(fd, fdf_info->map))
				ft_printf("\nAlmaceno");
			/*
			if (s)
			{
				ft_printf("%s", s[0]);
				ft_printf("%s", s[1]);
				ft_printf("%s", s[2]);
				while (*s)
					free(*(s++));
				free(s);
			}*/
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d", argv[1], fd);
	}
}
