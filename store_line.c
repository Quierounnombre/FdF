/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:49 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/22 16:00:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	copy_map(t_map *map, int lenght);
static int		calc_len(const char *s);
static int		move_len(const char *s);
static t_bool	expand_len(char c, t_bool *alloc, char *dup, t_bool *hexa);

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
				len = move_len(s);
				while (len--)
					s++;
				i++;
			}
			if (copy_map(map, i))
				return (true);
		}
	}
	return (false);
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

static t_bool	expand_len(char c, t_bool *alloc, char *dup, t_bool *hexa)
{
	static int	hexa_counter;

	ft_printf("Valor de dup: %d\n", *dup);
	if (ft_isspace(c) && *dup != c)
	{
		ft_printf("He encontrado un espacio\n");
		*alloc = true;
		hexa_counter = 0;
		*hexa = false;
	}
	else if (*hexa)
	{
		ft_printf("Entro en hexa\n");
		if (c == 'x' && *dup != c)
			*dup = c;
		if (ft_ishexa(c) && hexa_counter != 7)
			hexa_counter++;
	}
	else if (*dup == c)
	{
		ft_printf("He encontrado un duplicado\n");
		return (false);
	}
	else if (!ft_ishexa(c) && c != 'x' && c != ',' && c != ' ' && c != '-')
		return (false);
	if (c == '-' || c == 'x' || c == ' ')
	{
		ft_printf("He encontrado un <%c>\n", c);
		*dup = c;
	}
	return (true);
}

static int	calc_len(const char *s)
{
	size_t	i;
	t_bool	alloc_int;
	char	dup;
	t_bool	hexa;

	i = 0;
	alloc_int = true;
	dup = '\0';
	hexa = false;
	while (*s != '\0' && *s != '\n')
	{
		if (ft_isdigit(*s) && alloc_int)
		{
			i++;
			alloc_int = false;
			dup = 0;
			ft_printf("He encontrado un digito\n");
		}
		if (*s == ',')
		{
			ft_printf("He encontrado una coma\n");
			hexa = true;
		}
		if (!expand_len(*s, &alloc_int, &dup, &hexa))
			return (0);
		s++;
	}
	ft_printf("\n Calc_len devuelve con %d\n", i);
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
	if (s[i] == ',')
	{
		i += 3;
		while (ft_ishexa(s[i]))
			i++;
	}
	return (i);
}
