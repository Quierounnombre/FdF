/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:35 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/18 19:53:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	store_line(const char *s, t_map *map, int line);
static int		calc_len(const char *s);
static int		move_len(const char *s);

int	**store_file(int fd, t_map *map)
{
	char	*s;
	size_t	len;
	int		line;

	s = "Hola";
	len = 0;
	line = 0;
	while (s)
	{
		s = ft_get_next_line(fd);
		if (s)
		{
			if (store_line(s, map, line))
				line++;
		}
	}
	return (NULL);
}

static t_bool	store_line(const char *s, t_map *map, int line)
{
	int	i;
	int	len;

	i = 0;
	len = calc_len((char *)s);
	if (len)
	{
		map->map[0] = (int *) malloc(sizeof(int) * len);
		ft_printf("Longitud: %d", calc_len((char *)s));
		if (map->map[line])
		{
			while (s[i])
			{
				map->map[line][i] = ft_atoi(s);
				ft_printf("\n%d", map->map[line][i]);
				len = move_len(s);
				while (len--)
					s++;
			}
			/*
			if (map->map_size_x == 0)
				map->map_size_x = i;
			else if (map->map_size_x != i)
				return (false);
			map->map_size_y += 1;
			return (true);*/
		}
	}
	ft_printf("\nerror\n");
	return (false);
}

static int	calc_len(const char *s)
{
	size_t	i;
	size_t	j;
	t_bool	alloc_int;

	i = 0;
	alloc_int = true;
	while (s)
	{
		if (ft_isdigit(s[i]))
		{
			s++;
			if 
		}
		else if (ft_isspace(s[i]))
			s++;
	}
	if (s[i] != '\0')
		return (0);
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
