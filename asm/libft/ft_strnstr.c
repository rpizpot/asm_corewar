/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:12:54 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 22:49:03 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (need[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		if (hay[i] == need[j])
		{
			while (hay[i + j] == need[j] && hay[i + j] != '\0' && i + j < len)
			{
				if (!need[j + 1])
					return ((char *)hay + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
