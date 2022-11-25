/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:30:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/25 17:30:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_def/libftprintf.h"
# include <mlx.h>

# define MAX_ARGS 2

typedef struct s_pixel
{
	int	pixel;
	int	color;
}			t_pixel;

typedef struct s_map
{
	t_pixel	**map;
	int		map_size_x;
	int		map_size_y;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_FdF_info
{
	void	*mlx;
	t_img	*img;
	void	*win;
	t_map	*map;
}			t_FdF_info;

int			parse(int argc, char **argv);
t_bool		store_file(int fd, t_map *map);
t_bool		store_line(char *s, t_map *map, int line);
t_FdF_info	*init_struct(void);
void		free_map(t_map *map);
void		free_struct(t_FdF_info *fdf);
int			calc_len(char *s);
t_bool		init(int argc, char **argv, t_FdF_info **fdf_info);

#endif