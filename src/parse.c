/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:38:50 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 17:28:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	parse_log(int argc, const char c);

t_bool	parse(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (WIDTH < 100 || HEIGHT < 100)
		return (false);
	if (argc != MAX_ARGS)
	{
		parse_log(argc, argv[0][i]);
		return (false);
	}
	while (true)
	{
		if (argv[1][i] == '\0')
			break ;
		if (!(ft_isalnum(argv[1][i])) && argv[1][i] != ' ' && argv[1][i] != '_'
		&& argv[1][i] != '-' && argv[1][i] != '.' && argv[1][i] != '/')
		{
			parse_log(argc, argv[1][i]);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	parse_log(int argc, const char c)
{
	if (MAX_ARGS > argc)
		ft_printf("Me has introducido menos de %d argumentos\n", MAX_ARGS);
	else if (MAX_ARGS < argc)
		ft_printf("Me has introducido más de %d argumentos\n", MAX_ARGS);
	else
	{
		ft_printf("El caracter %c, no esta permitido\n", c);
	}
}
