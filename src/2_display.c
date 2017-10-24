/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:26:01 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 22:35:26 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		display(t_point **map, t_map *param)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(mlx, 1920, 1080, "FdF");

	mlx_key_hook(param->win, key_hook, *param);
	mlx_loop(param->mlx);
	return (TRUE);
}
