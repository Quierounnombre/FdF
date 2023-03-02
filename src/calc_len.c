/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:53 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/02 18:51:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus);
static t_bool	hexa_calc(char **s);
static t_bool	normal_len(char c, t_bool *alloc, size_t *i);

int	calc_len(char *s)
{
	size_t	i;
	t_bool	alloc_int;

	i = 0;
	alloc_int = true;
	while (*s != '\0')
	{
		if (*s == ',')
		{
			if (!hexa_calc(&s))
				return (0);
			i++;
		}
		else if (!normal_len(*s, &alloc_int, &i))
			return (0);
		s++;
	}
	return (i);
}

static t_bool	normal_len(char c, t_bool *alloc, size_t *i)
{
	static t_bool	minus;

	if (ft_isdigit(c))
	{
		if (*alloc)
		{
			(*i)++;
			*alloc = false;
			minus = false;
		}
	}
	else if (c == ' ' && minus == true)
		return (false);
	else if (!expand_len(c, alloc, &minus))
		return (false);
	return (true);
}

static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus)
{
	if (ft_isspace(c))
	{
		*alloc = true;
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
	if ((*(*s)) != ',')
		return (false);
	if ((*(++(*s))) != '0')
		return (false);
	if ((*(++(*s))) != 'x')
		return (false);
	(*s)++;
	while (**s)
	{
		if ((!ft_ishexa(**s)))
		{
			if (ft_isspace(**s))
				return (true);
			else
				return (false);
		}
		(*s)++;
	}
	return (true);
}
