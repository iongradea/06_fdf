/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:48:53 by igradea           #+#    #+#             */
/*   Updated: 2017/01/01 14:33:23 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	str[] = {'i', 'o', 'n'};

	printf("length : %i\n", (int)ft_strlen(str));
	printf("name : %s\n", ft_strdup(str));
	return (0);
}
