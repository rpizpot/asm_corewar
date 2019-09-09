/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:23:37 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:50 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_asm_list(t_asm **asm_list)
{
	if (!*asm_list || !asm_list)
		return ;
	free_asm_list(&(*asm_list)->next);
	ft_strdel(&(*asm_list)->one_line);
	free(*asm_list);
	(*asm_list) = NULL;
}
