/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:18:38 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/24 18:18:38 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*error_name(t_pars_asm *pars_asm, t_asm *asm_list)
{
	int i;
	int j;

	i = 0;
	while (asm_list->one_line[i] != '\"' && asm_list->one_line[i])
		i++;
	if (!asm_list->one_line[i])
		return ("Not name in the file\n");
	j = 0;
	while (asm_list->one_line[++i] != '\"' && j < PROG_NAME_LENGTH)
	{
		if (!asm_list->one_line[i] && asm_list->next)
		{
			asm_list = asm_list->next;
			i = -1;
		}
		else
			pars_asm->name[j++] = asm_list->one_line[i];
	}
	if (j > PROG_NAME_LENGTH)
		return ("Length more than 128\n");
	return (NULL);
}

char	*error_comment(t_pars_asm *pars_asm, t_asm *asm_list)
{
	int i;
	int j;

	i = 0;
	while (asm_list->one_line[i] != '\"' && asm_list->one_line[i])
		i++;
	if (!asm_list->one_line[i])
		return ("Not comment in the file\n");
	j = 0;
	while (asm_list->one_line[++i] != '\"' && j < COMMENT_LENGTH)
	{
		if (!asm_list->one_line[i] && asm_list->next)
		{
			asm_list = asm_list->next;
			i = -1;
		}
		else
			pars_asm->comment[j++] = asm_list->one_line[i];
	}
	if (j > PROG_NAME_LENGTH)
		return ("Length more than 2048\n");
	return (NULL);
}