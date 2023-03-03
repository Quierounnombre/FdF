/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:30:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/02 20:21:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft_def/libftprintf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "FdF_defines.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef NAME
#  define NAME "FDF"
# endif

# define MAX_ARGS 2

typedef struct s_pixel
{
	int			pixel;
	uint32_t	color;
}			t_pixel;

typedef struct s_map
{
	t_pixel	**map;
	int		map_size_x;
	int		map_size_y;
}			t_map;

typedef struct s_angle
{
	float	alpha;
	float	beta;
	float	gamma;
}				t_angle;

typedef struct s_dir_vectors
{
	t_vector2D	v_alpha;
	t_vector2D	v_beta;
	t_vector2D	v_gamma;
}					t_dir_vectors;

typedef struct s_perspective
{
	t_angle	isometrica;
	t_angle	dimetrica;
	t_angle	trimetrica;
	t_angle	caballera;
	t_angle	militar;
	int		current;
}				t_perspective;

typedef struct s_cam
{
	t_angle			*ang;
	t_vector3D		dim;
	t_dir_vectors	*dir_vec;
	t_vector2D		pos;
	t_perspective	*perps;
}				t_cam;

typedef struct s_FdF_info
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	void		*win;
	t_map		*map;
	t_cam		*cam;
}			t_FdF_info;

/*----STORE----*/

t_bool			store_file(int fd, t_map *map);
t_bool			store_line(char *s, t_map *map, int line);
t_FdF_info		*init_struct(void);
void			free_map(t_map *map);
void			free_struct(t_FdF_info *fdf);

/*----INIT && PARSE----*/

t_bool			parse(int argc, char **argv);
int				calc_len(char *s);
t_bool			init(int argc, char **argv, t_FdF_info **fdf_info);
void			ft_hooks(t_FdF_info *fdf);

/*----CLOSE----*/

void			close_fdf(void *fdf);

/*----DRAW----*/

void			draw(t_FdF_info	*fdf);
void			draw_lines(t_FdF_info *fdf, int i, int j, t_vector2D v);
t_vector2D		get_iso_perspective(t_vector3D v3, t_FdF_info *fdf);
void			set_dark(t_FdF_info *fdf);

/*-----CAM-----*/

t_vector3D		set_dimensions(t_map *map);
void			load_angles(t_angle *ang, t_dir_vectors *v);
void			select_perspective(t_FdF_info *fdf);

/*-----HOOKS-----*/

void			a_hook(t_FdF_info *fdf);
void			d_hook(t_FdF_info *fdf);
void			w_hook(t_FdF_info *fdf);
void			s_hook(t_FdF_info *fdf);
void			z_hook(t_FdF_info *fdf);
void			x_hook(t_FdF_info *fdf);
void			y_hook(t_FdF_info *fdf);
void			h_hook(t_FdF_info *fdf);
void			u_hook(t_FdF_info *fdf);
void			j_hook(t_FdF_info *fdf);
void			i_hook(t_FdF_info *fdf);
void			k_hook(t_FdF_info *fdf);
void			left_hook(t_FdF_info *fdf);
void			right_hook(t_FdF_info *fdf);
void			space_hook(t_FdF_info *fdf);
void			scroll_hook(double xdelta, double ydelta, void *param);

#endif