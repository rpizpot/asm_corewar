/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quantity_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:00:06 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 22:24:52 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	quantity_world(const char *s, char c)
{
	size_t i;
	size_t slova;

	i = 0;
	slova = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			slova++;
			while (s[i] != c && s[i])
				i++;
		}
	return (slova);
}
