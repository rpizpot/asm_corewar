/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse_asm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:38:51 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:55 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_arg(t_arg **arg)
{
	if (!*arg || !arg)
		return ;
	free_arg(&((*arg)->next));
	ft_strdel(&((*arg)->name_label));
	free(*arg);
	*arg = NULL;
}

void	free_comand_asm(t_comand_asm **comand_asm)
{
	if (!*comand_asm || !comand_asm)
		return ;
	free_comand_asm(&((*comand_asm)->next));
	ft_strdel(&((*comand_asm)->comand));
	ft_strdel(&((*comand_asm)->for_variables));
	free_arg(&((*comand_asm)->arg));
	free(*comand_asm);
	*comand_asm = NULL;
}

void	free_link_asm(t_link_asm **link_asm)
{
	if (!*link_asm || !link_asm)
		return ;
	free_link_asm(&((*link_asm)->next));
	ft_strdel(&((*link_asm)->link_name));
	free(*link_asm);
	*link_asm = NULL;
}

void	free_parse_asm(t_pars_asm **pars_asm)
{
	ft_strdel(&((*pars_asm)->name));
	ft_strdel(&((*pars_asm)->comment));
	free_comand_asm(&((*pars_asm)->comand_asm));
	free_link_asm(&((*pars_asm)->link_asm));
	if (*pars_asm)
	{
		free(*pars_asm);
		*pars_asm = NULL;
	}
}
