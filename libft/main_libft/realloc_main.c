/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:37:11 by igradea           #+#    #+#             */
/*   Updated: 2017/02/14 17:07:32 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		size;
	char	*str;
	int 	i;

	i = 0;
	size = ft_atoi(av[2]);
	str = (char*)malloc(sizeof(*str) * (size + 1));
	while (i < size)
	{
		printf("%c\n", av[1][i]);
		str[i] = av[1][i];
		i++;
	}
	str[i] = '\0';
	printf("malloc - str = %s\n", str);
	str = (char*)ft_realloc(str, 3);
	printf("realloc 3 - str = %s\n", str);
	str = (char*)ft_realloc(str, 10);
	printf("realloc 10 - str = %s\n", str);
	return (0 * ac);
}
