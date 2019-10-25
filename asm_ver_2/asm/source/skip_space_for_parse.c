/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_for_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:41:44 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/24 10:41:44 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	skip_space_for_parse(t_asm **asm_list)
{
	int		k;
	int		i;
	char	*new_line;

	k = 0;
	while (*asm_list)
		if (!ft_strcmp("\0", (*asm_list)->one_line))
			del_node(asm_list);
		else
		{
			i = skip_space((*asm_list)->one_line);
			if ((*asm_list)->one_line[i] != '#'
			&& (*asm_list)->one_line[i] != ';' && (*asm_list)->one_line[i])
			{
				k++;
				new_line = ft_strdup(&((*asm_list)->one_line[i]));
				ft_strdel(&(*asm_list)->one_line);
				(*asm_list)->one_line = new_line;
				(*asm_list)->line_num = k;
				*asm_list = (*asm_list)->next;
			}
			else
				del_node(asm_list);
		}
}
