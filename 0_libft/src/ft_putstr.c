/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:44:24 by igradea           #+#    #+#             */
/*   Updated: 2017/09/18 13:21:04 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr(char const *s)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(s);
	while (i < len)
		ft_putchar(s[i++]);
}
