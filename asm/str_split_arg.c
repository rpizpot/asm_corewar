/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:28:24 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/27 17:28:24 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t length(char *str)
{
	uint8_t len;

	while (*str && *str != ' ' && *str != ',' && *str != '\t'
			&& *str != COMMENT_CHAR)
	{
		len++;
		str++;
	}
	return (len);
}

uint8_t num_of_arg(char *str)
{
	uint8_t arg;

	arg = 0;
	while (*str && *str != COMMENT_CHAR)
		if (*str == ' ' || *str == ',' || *str == '\t')
			str++;
		else
		{
			arg++;
			while (*str && *str != ' ' && *str != ',' && *str != '\t'
			&& *str != COMMENT_CHAR)
				str++;
		}
	return (arg);
}

char	**str_split_arg(char *str)
{
	char **arg;
	uint8_t j;
	uint8_t k;

	j = 0;
	if (!(arg = (char **)malloc(sizeof(char *) * (num_of_arg(str) + 1))))
		return (NULL);
	while (*str && *str != '#')
		if (*str == ' ' || *str == ',' || *str == '\t')
			str++;
		else
		{
			k = 0;
			arg[j] = ft_strnew(length(str));
			while (*str && *str != ' ' && *str != ',' && *str != '\t'
					&& *str != COMMENT_CHAR)
			{
				arg[j][k++] = *str;
				str++;
			}
			j++;
		}
	arg[j] = NULL;
	return(arg);
}