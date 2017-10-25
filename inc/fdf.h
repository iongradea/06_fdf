/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:23:25 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 17:34:41 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>


# define LINE_READ_GNL 1
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define NONE -2
# define ERROR_MAP -3
# define ERROR_GNL -4
# define ERROR_INT -5

# define COMPRESS_Z 3
# define ADJUST_Z 1
# define REV_Z -1
# define ZOOM 20
# define WIN_X 1920
# define WIN_Y 1080
# define ZOOM_MIN 78
# define ZOOM_PLUS 69
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define U 32
# define D 2
# define R 15
# define COLOR 8

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			x_proj;
	float			y_proj;
	int				in_tab;
}					t_point;

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	int				line_len;
	int				nb_pts;
	int				zoom;
	float			adjust_z;
	int				rev_z;
	int				win_x;
	int				win_y;
	t_point			*map_pts;
}					t_map;

typedef struct		s_bresen
{
	float			dx;
	float			dy;
	float			cumul;
	float			xinc;
	float			yinc;
	float			x;
	float			y;
}					t_bresen;

int					ch_map_err(int fd, t_map *map);
int					parser(t_point *map_pts, t_map map_c, int fd);
int					display(t_point *map_pts, t_map *map_c);
int					proj_iso(t_point *map, t_map map_c);
int					draw(t_point *map, t_map map_c);
int					key_hook(int keycode, t_map *map);

#endif
