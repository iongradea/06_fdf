/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ch_in_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:36:12 by igradea           #+#    #+#             */
/*   Updated: 2017/10/25 18:02:29 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ch_char(char c)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-' && c != '+')
		return (ERROR_MAP);
	return (TRUE);
}

static int	ch_plus_minus_sp(char *str)
{
	if ((*str == '-' || *str == '+') && !ft_isdigit(*(str + 1)))
		return (ERROR_MAP);
	if (*str == ' ' && !ft_isdigit(*(str + 1)) && *(str + 1) != '-'
			&& *(str + 1) != '+' && *(str + 1) != ' ')
		return (ERROR_MAP);
	return (TRUE);
}

static int	ch_line(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	while (line[i] && line[i + 1])
	{
		if (ch_char(line[i]) == ERROR_MAP)
			return (ERROR_MAP);
		if (ch_plus_minus_sp(line + i) == ERROR_MAP)
			return (ERROR_MAP);
		i++;
	}
	if (i == len - 1 && line[i] != ' ' && !ft_isdigit(line[i]))
		return (ERROR_MAP);
	return (TRUE);
}

static void	free_ptr_dbl(void **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
}

int			ch_map_err(int fd, t_map *map)
{
	int		ret;
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	while ((ret = get_next_line(fd, &line)) == LINE_READ_GNL)
	{
		if (ch_line(line) == ERROR_MAP)
			return (ERROR_MAP);
		tab = ft_strsplit(line, ' ');
		if (i == 0)
			map->line_len = ft_tablen(tab);
		else if (map->line_len != ft_tablen(tab))
			return (ERROR_MAP);
		i++;
		free_ptr_dbl((void**)tab);
	}
	if (ret == ERROR)
		return (ERROR);
	map->nb_pts = i * map->line_len;
	if (map->nb_pts < 2)
		return (ERROR_MAP);
	free(tab);
	return (TRUE);
}
