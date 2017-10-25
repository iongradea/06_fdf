/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:48:21 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 17:01:51 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	is_nb(char c)
{
	if (c == '-' || c == '+' || ft_isdigit(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

static void	new_point(t_point *p, int x, int y, int z)
{
	p->x = x * 1.0;
	p->y = y * 1.0;
	p->z = z * 1.0;
	p->x_proj = NONE;
	p->y_proj = NONE;
	p->in_tab = TRUE;
}

static void	set_point_as_end(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->x_proj = NONE;
	p->y_proj = NONE;
	p->in_tab = FALSE;
}

static int	go_to_next_nb(char *line, int pos)
{
	while (line[pos] == ' ')
		pos++;
	while (line[pos] && is_nb(line[pos]))
		pos++;
	if (line[pos] == ' ')
		pos++;
	return (pos);
}

int			parser(t_point *map_pts, t_map map_c, int fd)
{
	int		x;
	int		y;
	int		ret;
	char	*line;
	int		pos;
	int		n;

	y = 0;
	while ((ret = get_next_line(fd, &line)) == LINE_READ_GNL)
	{
		x = 0;
		pos = 0;
		while (line[pos]) 
		{
			if (ft_atoi_max_int(line + pos, &n) == ERROR)
				return (ERROR_INT);
			new_point(map_pts + y * map_c.line_len + x, x, y, n);
			x++;
			pos = go_to_next_nb(line, pos);
		}
		y++;
	}
	set_point_as_end(map_pts + y * map_c.line_len);
	if (ret == ERROR)
		return (ERROR);
	return (TRUE);
}
