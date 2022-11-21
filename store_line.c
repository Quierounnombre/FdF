/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:49 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/21 14:54:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	copy_map(t_map *map, int lenght);
static int		calc_len(const char *s);
static int		move_len(const char *s);
static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus, t_bool *space);

t_bool	store_line(const char *s, t_map *map, int line)
{
	int	i;
	int	len;

	i = 0;
	len = calc_len((char *)s);
	if (len)
	{
		map->map[line] = (int *) malloc(sizeof(int) * len);
		if (map->map[line])
		{
			while (s && *s != '\n')
			{
				map->map[line][i] = ft_atoi(s);
				ft_printf("Valor de %d %d -> %d\n", line, i, map->map[line][i]);
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
	t_bool	double_minus;
	t_bool	double_space;

	i = 0;
	alloc_int = true;
	double_minus = false;
	double_space = false;
	while (*s != '\0')
	{
		if (ft_isdigit(*s))
		{
			if (alloc_int)
			{
				i++;
				alloc_int = false;
				double_space = false;
			}
		}
		if (expand_len(*s, &alloc_int, &double_minus, &double_space))
			s++;
		else
			return (0);
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

static t_bool	expand_len(char c, t_bool *alloc, t_bool *minus, t_bool *space)
{
	ft_printf("valor de alloc %d\n", *alloc);
	ft_printf("Valor de minus %d\n", *minus);
	ft_printf("Valor de space %d\n", *space);
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
