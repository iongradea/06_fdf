/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:53:56 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 19:04:55 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_atoi_max_int(const char *str, int *n)
{
	long	nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		if (nb < INT_MIN || nb > INT_MAX)
			return (ERROR);
	}
	*n = (int)nb * sign;
	return (TRUE);
}
