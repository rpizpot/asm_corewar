/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:21:38 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:42 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_all(t_pars_asm **pars_asm, t_asm **asm_list)
{
	if (!*pars_asm || !*asm_list)
		exit(2);
	while ((*asm_list)->previous)
		(*asm_list) = (*asm_list)->previous;
	while ((*pars_asm)->comand_asm->previous)
		(*pars_asm)->comand_asm = (*pars_asm)->comand_asm->previous;
	free_asm_list(asm_list);
	free_parse_asm(pars_asm);
	exit(1);
}
