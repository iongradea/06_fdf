/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 08:56:30 by igradea           #+#    #+#             */
/*   Updated: 2017/01/17 18:54:34 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	size_t	i;

	i = 3;
	printf("ft_memcpy: %s\n", ft_memcpy(dst, av[1], i));
	ft_putnbr(1514515);
	printf("memcpy   : %s\n", memcpy(dst2, av[2], i));
	return (ac * 0);
}
