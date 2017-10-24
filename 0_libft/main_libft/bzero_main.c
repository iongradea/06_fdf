/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:25:10 by igradea           #+#    #+#             */
/*   Updated: 2016/12/19 18:43:27 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	void	*s;
	size_t	n;
	
	n = 5;
	s = (char*)malloc(sizeof(char) * n);
	printf("%s\n", s);
	((unsigned char*)s)[0] = '1';
	write(1, s, 5);
	printf("\n%s\n", ((unsigned char *)s));
	ft_bzero(s, n);
	printf("%s\n", s);
	return (0);
}
