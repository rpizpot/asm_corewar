/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:57:13 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 22:25:21 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*world(const char *s, char c, size_t start)
{
	size_t	i;
	char	*new_slovo;

	i = 0;
	new_slovo = (char *)malloc(sizeof(char) * long_world(s, c, start) + 1);
	if (!new_slovo)
	{
		free(new_slovo);
		return (NULL);
	}
	while (s[start + i] != c && s[start + i])
	{
		new_slovo[i] = s[start + i];
		i++;
	}
	new_slovo[i] = '\0';
	return (new_slovo);
}
