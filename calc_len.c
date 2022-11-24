/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:53 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/24 16:39:42 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus, t_bool *space);
static t_bool	hexa_calc(char **s);
static t_bool	normal_len(char c, t_bool *alloc, size_t *i, t_bool *space);

int	calc_len(char *s)
{
	size_t	i;
	t_bool	alloc_int;
	t_bool	double_space;

	i = 0;
	alloc_int = true;
	double_space = false;
	while (*s != '\0')
	{
		if (*s == ',')
		{
			if (!hexa_calc(&s))
				return (0);
		}
		else if (!normal_len(*s, &alloc_int, &i, &double_space))
			return (0);
		s++;
	}
	return (i);
}

static t_bool	normal_len(char c, t_bool *alloc, size_t *i, t_bool *space)
{
	static t_bool	minus;

	if (ft_isdigit(c))
	{
		if (*alloc)
		{
			(*i)++;
			*alloc = false;
			*space = false;
			minus = false;
		}
	}
	else if (c == ' ' && minus == true)
		return (false);
	else if (!expand_len(c, alloc, &minus, space))
		return (false);
	return (true);
}

static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus, t_bool *space)
{
	if (ft_isspace(c))
	{
		*alloc = true;
		if (*space)
			return (false);
		else
			*space = true;
		return (true);
	}
	else if (*minus && c == '-')
		return (false);
	else if (c == '-')
	{
		*minus = true;
		return (true);
	}
	else if (!ft_isdigit(c))
		return (false);
	return (true);
}

static t_bool	hexa_calc(char **s)
{
	int		counter;
	t_bool	coma;

	counter = 0;
	coma = false;
	while (**s)
	{
		if (**s == ',' && coma == false)
		{
			counter = 9;
			coma = true;
		}
		else if (**s != '0' && counter == 8)
			return (false);
		else if (**s != 'x' && counter == 7)
			return (false);
		else if ((!ft_ishexa(**s) && counter >= 0 && counter <= 6))
			return (false);
		counter--;
		if (counter == 0)
			break ;
		(*s)++;
	}
	return (true);
}
