/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:23:25 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 14:07:15 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

# define BUFF_SIZE 1500
# define TRUE -1
# define FALSE 0
# define ERROR -2
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

#endif
