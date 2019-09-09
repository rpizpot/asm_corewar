/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_alist_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:08:37 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:55:46 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_asm	*add_alist_back(t_asm *old, t_asm *new)
{
	t_asm *start;

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
