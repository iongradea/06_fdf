/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:23:25 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 02:29:31 by iongradea        ###   ########.fr       */
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
# define ERROR_MAP -2
# define ERROR_GNL -3
# define ERROR_INT -4

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				in_tab;
}					t_point;

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	int				line_len;
	int				nb_pts;
}					t_map;

int					ch_map_err(int fd, t_map *map);
int					parser(t_point *map_pts, t_map map_c, int fd);

#endif
