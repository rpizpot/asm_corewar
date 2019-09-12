/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:58:54 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 22:24:26 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	long_world(const char *s, char c, size_t start)
{
	size_t i;

	i = 0;
	while (s[start] != c && s[start])
	{
		i++;
		start++;
	}
	return (i);
}
