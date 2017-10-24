/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:12:24 by igradea           #+#    #+#             */
/*   Updated: 2017/01/13 17:39:48 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *s = "*************";
	char **res = ft_strsplit(s, '*');

	printf("%s\n", res[0]);
	printf("%s\n", (ft_strsplit("*salut*les***etudiants*", '*')[1]));
	printf("%s\n", (ft_strsplit("*salut*les***etudiants*", '*')[2]));
	printf("sizeof int : %lu\n", sizeof(int));
	printf("sizeof char : %lu\n", sizeof(char));
	return (0);
}
