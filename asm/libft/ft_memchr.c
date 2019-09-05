/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:37:32 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/09 17:15:31 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *source, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < (unsigned long)n)
	{
		if (((unsigned char *)source)[i] == (unsigned char)c)
			return (((void *)source) + i);
		i++;
	}
	return (NULL);
}
