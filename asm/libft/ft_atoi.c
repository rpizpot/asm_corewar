/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:28:59 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 20:46:10 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int index;
	int result;
	int flag;

	index = 0;
	flag = 1;
	result = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
			|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
		flag = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		if (index >= 19 && flag == -1)
			return (0);
		if (index >= 19 && flag == 1)
			return (-1);
		index++;
	}
	return (result * flag);
}
