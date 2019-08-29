/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:45:21 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/06 02:12:42 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (need[j] == 0)
		return ((char *)hay);
	while (hay[i])
	{
		if (hay[i] == need[j])
		{
			while (hay[i + j] == need[j] && hay[i + j] != 0)
				j++;
			if (j == ft_strlen(need))
				return ((char *)hay + i);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}
