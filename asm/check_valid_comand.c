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

int	check_valid_comand(char *comand)
{
	if (!ft_strcmp(comand, COR_LIVE))
		return (0);
	else if (!ft_strcmp(comand, COR_LB))
		return (0);
	else if (!ft_strcmp(comand, COR_ST))
		return (0);
	else if (!ft_strcmp(comand, COR_ADD))
		return (0);
	else if (!ft_strcmp(comand, COR_SUB))
		return (0);
	else if (!ft_strcmp(comand, COR_AND))
		return (0);
	else if (!ft_strcmp(comand, COR_OR))
		return (0);
	else if (!ft_strcmp(comand, COR_XOR))
		return (0);
	else if (!ft_strcmp(comand, COR_ZJMP))
		return (0);
	else if (!ft_strcmp(comand, COR_LDI))
		return (0);
	else if (!ft_strcmp(comand, COR_STI))
		return (0);
	else if (!ft_strcmp(comand, COR_FORK))
		return (0);
	else if (!ft_strcmp(comand, COR_LLD))
		return (0);
	else if (!ft_strcmp(comand, COR_LLDI))
		return (0);
	else if (!ft_strcmp(comand, COR_LFORK))
		return (0);
	else if (!ft_strcmp(comand, COR_AFF))
		return (0);
	return (1);
}