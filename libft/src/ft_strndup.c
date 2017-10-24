/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:42:00 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 20:43:59 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	n = i;
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
