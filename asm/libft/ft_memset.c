/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:34:45 by rpizpot           #+#    #+#             */
/*   Updated: 2019/05/13 20:51:30 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)b;
	while (i < len)
		dest[i++] = (unsigned char)c;
	return (b);
}
