/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:23:25 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 03:40:17 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

# define ZOOM 20
# define LINE_READ_GNL 1
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define NONE -2
# define ERROR_MAP -3
# define ERROR_GNL -4
# define ERROR_INT -5

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
}					t_map;

int					ch_map_err(int fd, t_map *map);
int					parser(t_point *map_pts, t_map map_c, int fd);
int					display(t_point *map_pts, t_map *map_c);
int					proj_iso(t_point *map, int zoom);

#endif
