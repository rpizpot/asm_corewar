/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:57:09 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/08 04:59:11 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	e;
	char	*new_str;

	if (!s)
		return (NULL);
	st = 0;
	e = ft_strlen(s) - 1;
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && (s[st] != '\0'))
		st++;
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && e > 0)
		e--;
	if (st > e)
	{
		new_str = (char *)malloc(sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = (char *)malloc(sizeof(char) * (e - st) + 2);
	if (!new_str)
		return (NULL);
	return (ft_newtrim(new_str, s, st, e));
}
