/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializ_corewar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:54:41 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:59 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	inicializ_corewar(t_pars_asm *pars_asm)
{
	pars_asm->name = ft_strnew(PROG_NAME_LENGTH);
	pars_asm->comment = ft_strnew(COMMENT_LENGTH);
	pars_asm->comand_asm = NULL;
	pars_asm->link_asm = NULL;
}
