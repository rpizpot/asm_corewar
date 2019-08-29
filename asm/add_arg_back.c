/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:38:46 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/29 16:38:46 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_arg	*add_arg_back(t_arg *old, t_arg *new)
{
	t_arg *start;

	start = old;
	if (!start)
	{
		start = new;
		return (start);
	}
	while (old->next)
		old = old->next;
	old->next = new;
	return (start);
}