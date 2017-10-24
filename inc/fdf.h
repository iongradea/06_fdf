/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:23:25 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 15:10:07 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

# define TRUE -5
# define FALSE 0
# define ERROR -1
# define ERROR_MAP -3

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_param
{
	void			*mlx;
	void			*win;
}					t_param;

typedef struct		s_map
{
	int				line_len;
	int				nb_pts;
}					t_map;

int					ch_map_err(int fd, t_map *map, char ***tab);
void				free_ptr_dbl(void **tab);

#endif
