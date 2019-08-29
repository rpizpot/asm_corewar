/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_comand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:25:00 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/25 17:25:00 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	*check_valid_comand(char *comand)
{
	if (!ft_strcmp(comand, COR_LIVE))
		return (0);
	else if (!ft_strcmp(comand, COR_LB))
		return (1);
	else if (!ft_strcmp(comand, COR_ST))
		return (2);
	else if (!ft_strcmp(comand, COR_ADD))
		return (3);
	else if (!ft_strcmp(comand, COR_SUB))
		return (4);
	else if (!ft_strcmp(comand, COR_AND))
		return (5);
	else if (!ft_strcmp(comand, COR_OR))
		return (6);
	else if (!ft_strcmp(comand, COR_XOR))
		return (7);
	else if (!ft_strcmp(comand, COR_ZJMP))
		return (8);
	else if (!ft_strcmp(comand, COR_LDI))
		return (9);
	else if (!ft_strcmp(comand, COR_STI))
		return (10);
	else if (!ft_strcmp(comand, COR_FORK))
		return (11);
	else if (!ft_strcmp(comand, COR_LLD))
		return (12);
	else if (!ft_strcmp(comand, COR_LLDI))
		return (13);
	else if (!ft_strcmp(comand, COR_LFORK))
		return (14);
	else if (!ft_strcmp(comand, COR_AFF))
		return (15);
	return (-1);
}