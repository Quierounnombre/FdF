/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/03 16:23:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	copy_map(t_map *map, int lenght);
static int		move_len(const char *s);
static void		store_pixel(int *i, int line, t_map *map, char **s);

t_bool	store_line(char *s, t_map *map, int line)
{
	int	i;
	int	len;

	i = 0;
	len = calc_len((char *)s);
	if (len)
	{
		map->map[line] = (t_pixel *) malloc(sizeof(t_pixel) * len);
		if (map->map[line])
		{
			while (*s != '\0' && *s != '\n')
				store_pixel(&i, line, map, &s);
			if (copy_map(map, i))
				return (true);
		}
	}
	return (false);
}

static void	store_pixel(int *i, int line, t_map *map, char **s)
{
	int	len;

	map->map[line][*i].pixel = ft_atoi((*s));
	len = move_len(*s);
	while (len--)
		(*s)++;
	if (**s == ',')
	{
		(*s) += 3;
		map->map[line][*i].color = ft_atoi_base((*s), "0123456789ABCDEF");
		if (!(map->map[line][*i].color))
			map->map[line][*i].color = ft_atoi_base((*s), "0123456789abcdef");
		while (!ft_isspace(**s))
			(*s)++;
	}
	else
		map->map[line][*i].color = 0x00FFFF;
	(*i)++;
}

static t_bool	copy_map(t_map *map, int lenght)
{
	t_pixel	**new_map;
	int		i;

	i = 0;
	new_map = (t_pixel **)malloc(sizeof(t_pixel *) * (map->map_size_y + 1));
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
	while (ft_isspace(s[i]))
		i++;
	return (i);
}
