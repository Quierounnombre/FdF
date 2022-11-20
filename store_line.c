/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:49 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/20 18:33:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	copy_map(t_map *map, int lenght);
static int		calc_len(const char *s);
static int		move_len(const char *s);
static t_bool	cheeck_for_chars(const char *s);

t_bool	store_line(const char *s, t_map *map, int line)
{
	int	i;
	int	len;

	i = 0;
	len = calc_len((char *)s);
	if (len && cheeck_for_chars(s))
	{
		map->map[line] = (int *) malloc(sizeof(int) * len);
		if (map->map[line])
		{
			while (s && *s != '\n')
			{
				map->map[line][i] = ft_atoi(s);
				len = move_len(s);
				while (len--)
					s++;
				i++;
			}
			if (copy_map(map, i))
				return (true);
		}
	}
	ft_printf("\nerror\n");
	return (false);
}

static int	calc_len(const char *s)
{
	size_t	i;
	t_bool	alloc_int;

	i = 0;
	alloc_int = true;
	while (*s != '\0')
	{
		if (ft_isdigit(*s))
		{
			s++;
			if (alloc_int)
			{
				i++;
				alloc_int = false;
			}
		}
		else if (ft_isspace(*s))
		{
			s++;
			alloc_int = true;
		}
		else if (*s == '-')
			s++;
	}
	return (i);
}

static int	move_len(const char *s)
{
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

static t_bool	copy_map(t_map *map, int lenght)
{
	int		**new_map;
	int		i;

	i = 0;
	new_map = (int **)malloc(sizeof(int *) * (map->map_size_y + 1));
	if (new_map)
	{
		while (i != map->map_size_y)
		{
			new_map[i] = map->map[i];
			i++;
		}
		free(map->map);
		map->map = new_map;
		map->map_size_y += 1;
		if (map->map_size_x == 0)
		map->map_size_x = lenght;
		else if (map->map_size_x != lenght)
			return (false);
		return (true);
	}
	return (false);
}

static t_bool	cheeck_for_chars(const char *s)
{
	t_bool	double_minus;

	double_minus = false;
	while (s)
	{
		if (double_minus && *s == '-')
			return (false);
		else if (double_minus)
			double_minus = false;
		if (!ft_isdigit(*s) && !ft_isspace(*s) && *s != '-')
		{
			ft_printf("Entro");
			return (false);
		}
		if (*s == '-')
			double_minus = true;
		s++;
	}
	return (true);
}
