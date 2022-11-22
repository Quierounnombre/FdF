/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_line_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:53 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/22 20:56:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	expand_len(char *s, t_bool *alloc, t_bool *minus,
					t_bool *space);
static t_bool	hexa_calc(char *s, t_bool *hexa);

int	calc_line_size(const char *s)
{
	size_t	i;
	t_bool	alloc_int;
	t_bool	double_minus;
	t_bool	double_space;

	i = 0;
	alloc_int = true;
	double_minus = false;
	double_space = false;
	while (*s != '\0' && *s != '\n')
	{
		ft_printf("Caracter <%c>\n", *s);
		if (ft_isdigit(*s) && alloc_int)
		{
			i++;
			alloc_int = false;
			double_space = false;
			double_minus = false;
		}
		else if (!expand_len((char *)s, &alloc_int, &double_minus
				, &double_space))
			return (0);
		s++;
	}
	return (i);
}

static t_bool	expand_len(char *s, t_bool *alloc, t_bool *minus, t_bool *space)
{
	static t_bool	hexa;

	if (ft_isdigit(*s) && !hexa)
		return (true);
	if (*minus && *s == ' ')
		return (false);
	else if (ft_isspace(*s))
	{
		*alloc = true;
		if (*space)
			return (false);
		else
			*space = true;
		return (true);
	}
	else if (*minus && *s == '-')
		return (false);
	else if (*s == '-')
	{
		*minus = true;
		return (true);
	}
	else if (!hexa_calc(s, &hexa))
		return (false);
	return (true);
}

static t_bool	hexa_calc(char *s, t_bool *hexa)
{
	static t_bool	error;
	static int		counter;

	ft_printf("V de counter %d para %c\n\n", counter, *s);
	if (*s == ',')
	{
		*hexa = true;
		counter = 9;
	}
	else if (*s != '0' && counter == 8 && *hexa)
		return (false);
	else if (*s != 'x' && counter == 7 && *hexa)
		return (false);
	else if ((!ft_ishexa(*s) && counter >= 0 && counter <= 6) && *hexa)
		error = true;
	counter--;
	ft_printf("C %d H %d\n", counter, *hexa);
	if (counter == 0 && *hexa)
		*hexa = false;
	ft_printf("H %d\n", *hexa);
	ft_printf("error %d\n", error);
	if (!error)
		return (true);
	return (false);
}
