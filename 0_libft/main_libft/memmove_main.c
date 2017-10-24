/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:40:21 by igradea           #+#    #+#             */
/*   Updated: 2017/02/11 17:42:20 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	dst[10];
	char	src[10] = "dfdsfs"; 

	ft_bzero(dst, 10);
	ft_memmove(dst, src, 4);
	printf("address dst =  %p, value dst = %s\n", dst, dst);
	printf("address src =  %p, value src = %s\n", src, src);
	return (0);
}
