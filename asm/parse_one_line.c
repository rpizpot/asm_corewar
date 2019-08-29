/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:47:43 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/27 16:47:43 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 	parse_link(t_pars_asm *pars_asm, t_asm *asm_list, char *check,
		char **for_link)
{
}

void	parse_one_line(t_pars_asm *pars_asm, t_asm *asm_list, char *check)
{
	char	*for_link;
	char	*for_comand;
	char 	*str;
	int		i;
	t_comand_asm	*comand_asm;
	t_link_asm		*link_asm;


	for_link = NULL;
	for_comand = NULL;
	while (*check)
	{
		if (*check == LABEL_CHAR && !for_link)
		{
			link_asm = link_asm_new_list(asm_list->one_line,
					asm_list->line_num, (check - asm_list->one_line));
			pars_asm->link_asm = add_new_link_list(pars_asm->link_asm,
					link_asm);
			for_link = check;
		}
		else if ((*check == DIRECT_CHAR || *check == ' ') && !for_comand)
		{
			if (for_link)
			{
				check = ++for_link;
				while (*check == ' ' && *check == '\t')
					check++;
				str = ft_strnew(5);
				i = 0;
				while (*check != '%' && *check != ' '
						&& i < 5)
				{
					str[i++] = *check;
					check++;
				}
				comand_asm = comand_asm_new_list(str,
						asm_list->line_num, check);
				pars_asm->comand_asm = add_new_comand_asm_list(
						pars_asm->comand_asm, comand_asm);
				ft_bzero(str, 5);
			}
			else if (!for_link)
			{
				str = ft_strnew(5);
				for_link = asm_list->one_line;
				i = 0;
				while (*for_link != '%' && *for_link != ' '
						&& i < 5)
				{
					str[i++] = *for_link;
					for_link++;
				}
				comand_asm = comand_asm_new_list(str,
						asm_list->line_num, check);
				pars_asm->comand_asm = add_new_comand_asm_list(
						pars_asm->comand_asm, comand_asm);
				ft_bzero(str, 5);
				check = for_link;
			}
			for_comand = check;
		}
		if (*check)
			check++;
	}
}