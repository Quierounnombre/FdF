/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:38:50 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 15:26:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	parse_log(int argc, const char c);

int	parse(int argc, const char **argv)
{
	if (argc != MAX_ARGS)
	{
		parse_log(argc, *argv[1]);
		return (false);
	}
	while (true)
	{
		if (!(ft_isalnum(*argv[1])))
		{
			parse_log(argc, *argv[1]);
			return (false);
		}
		argv[1]++;
		if (*argv[1] == '\0')
			break ;
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
		ft_printf("El caracter %c, no esta permitido", c);
	}
}
