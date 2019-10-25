/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:32:08 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/24 10:32:08 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		skip_space(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

void	norm_del_node(t_asm **asm_list, t_asm *del)
{
	if ((*asm_list)->next)
	{
		*asm_list = (*asm_list)->next;
		(*asm_list)->previous = del->previous;
	}
	(*asm_list) = del->previous;
	(*asm_list)->next = del->next;
	(*asm_list) = (*asm_list)->next;
}

void	del_node(t_asm **asm_list)
{
	t_asm *del;

	ft_strdel(&(*asm_list)->one_line);
	del = *asm_list;
	if ((*asm_list)->previous)
		norm_del_node(asm_list, del);
	else if (!(*asm_list)->previous)
	{
		if ((*asm_list)->next)
		{
			*asm_list = (*asm_list)->next;
			(*asm_list)->previous = NULL;
		}
		else
			*asm_list = (*asm_list)->next;
	}
	free(del);
}

void	find_name_comment(t_asm **asm_list, t_pars_asm *pars_asm)
{
	int		i;

	while (*asm_list)
	{
		if (!ft_strcmp("\0", (*asm_list)->one_line))
			del_node(asm_list);
		else
		{
			i = skip_space((*asm_list)->one_line);
			if ((*asm_list)->one_line[i] == '#'
			|| (*asm_list)->one_line[i] == ';' || !(*asm_list)->one_line[0])
				del_node(asm_list);
			else if ((*asm_list)->one_line[i] == '.'
			|| (*asm_list)->one_line[i])
				return ;
			else if (!(*asm_list)->next)
				error_in_name_or_comment_2(&pars_asm, asm_list,
						"\033[31mNo code\033[m\n");
			else
				*asm_list = (*asm_list)->next;
		}
	}
}
