/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:32:08 by igradea           #+#    #+#             */
/*   Updated: 2017/10/24 22:17:30 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		number_of_words(char const *s, char c)
{
	int		n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n += 1;
			while (*s != c && *s)
				s++;
		}
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**output;

	i = 0;
	n = number_of_words(s, c);
	if (!(output = (char **)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j])
			j++;
		output[i] = ft_strndup(s, j);
		i++;
		s += j;
	}
	output[i] = 0;
	return (output);
}
