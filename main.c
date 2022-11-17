/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:17 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 16:15:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (parse(argc, (const char **)argv))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			store_file(fd);
		}
		else
			ft_printf("No he podido abrir el archivo");
	}
}