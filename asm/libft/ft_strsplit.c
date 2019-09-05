/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 05:04:07 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/20 19:34:36 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**new_split;
	size_t	i;
	size_t	slova;

	i = 0;
	slova = 0;
	if (!s)
		return (NULL);
	new_split = (char **)malloc(sizeof(char *) * quantity_world(s, c) + 1);
	if (!new_split)
	{
		free(new_split);
		return (NULL);
	}
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			new_split[slova++] = world(s, c, i);
			while (s[i] != c && s[i])
				i++;
		}
	new_split[slova] = NULL;
	return (new_split);
}
