/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:35:20 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/06 02:24:22 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t l_s;

	l_s = ft_strlen(s);
	while (l_s > 0)
	{
		if (((char*)s)[l_s] == (char)c)
			return ((char*)s + l_s);
		l_s--;
	}
	if (((char*)s)[l_s] == (char)c)
		return ((char*)s + l_s);
	else
		return (NULL);
}
