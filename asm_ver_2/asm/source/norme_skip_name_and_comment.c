/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_skip_name_and_comment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:01:22 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/24 12:01:22 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	norme_skip_name_and_comment(t_pars_asm *pars_asm, t_asm **asm_list)
{
	int i;

	while (*asm_list)
	{
		if (!ft_strcmp("\0", (*asm_list)->one_line))
			del_node(asm_list);
		else
		{
			i = skip_space((*asm_list)->one_line);
			if ((*asm_list)->one_line[i] == '#' ||
			(*asm_list)->one_line[i] == ';' || !(*asm_list)->one_line[0])
				del_node(asm_list);
			else if (ft_strchr(LABEL_CHARS, (*asm_list)->one_line[i])
					|| (*asm_list)->one_line[i] == '.')
				return ;
			else if (!(*asm_list)->next)
				error_in_name_or_comment_2(&pars_asm, asm_list,
						"\033[31mNo code\033[m\n");
			else
				*asm_list = (*asm_list)->next;
		}
	}
}

void	check_n_c(t_pars_asm *pars_asm, t_asm **asm_list, int flag_n,
		int flag_c)
{
	if (!*pars_asm->name && !*pars_asm->comment && !flag_n && !flag_c)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot name and comment in file\033[m\n");
	else if (!*pars_asm->name && !flag_n)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot name in file\033[m\n");
	else if (!*pars_asm->comment && !flag_c)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot comment in file\033[m\n");
}
