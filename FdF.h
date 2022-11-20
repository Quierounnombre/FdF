/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:30:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/20 18:17:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_def/libftprintf.h"

# define MAX_ARGS 2

typedef struct s_map
{
	int	**map;
	int	map_size_x;
	int	map_size_y;
}			t_map;

typedef struct s_FdF_info
{
	t_map	*map;
}			t_FdF_info;

int			parse(int argc, char **argv);
int			**store_file(int fd, t_map *map);
t_bool		store_line(const char *s, t_map *map, int line);
t_FdF_info	*init_struct(void);

#endif