/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:55:50 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 22:31:35 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_back_memmove(void *dest_b, const void *source_b, size_t n_b)
{
	n_b--;
	while (n_b > 0)
	{
		((unsigned char *)dest_b)[n_b] = ((unsigned char *)source_b)[n_b];
		n_b--;
	}
	((unsigned char *)dest_b)[n_b] = ((unsigned char *)source_b)[n_b];
	return (dest_b);
}

void		*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if ((source + i) == dest)
			return (ft_back_memmove(dest, source, n));
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (dest);
}
