/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_comand_asm_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:04:16 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:55:57 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_comand_asm	*add_new_comand_asm_list(t_comand_asm *old, t_comand_asm *new)
{
	t_comand_asm *start;

	start = old;
	if (!start)
	{
		start = new;
		return (start);
	}
	while (old->next)
		old = old->next;
	new->previous = old;
	old->next = new;
	return (start);
}
