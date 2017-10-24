/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:43:38 by igradea           #+#    #+#             */
/*   Updated: 2016/12/19 17:10:30 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	void	*str;
	size_t	len;

	len = 5;
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	printf("%s\n", ft_memset(str, 'a', len));
	return (0);
}
