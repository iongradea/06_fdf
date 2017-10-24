/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:34:03 by igradea           #+#    #+#             */
/*   Updated: 2017/01/13 18:03:26 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("0 : %s\n", ft_itoa(0));
	printf("-2147... : %s\n", ft_itoa(-2147483648));
	printf("156 : %s\n", ft_itoa(156));
	return (0);
}
