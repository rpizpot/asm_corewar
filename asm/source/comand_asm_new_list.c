/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_asm_new_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:13:17 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:31 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_comand_asm	*comand_asm_new_list(char *line, uint8_t num_line, char *for_va,
		int a)
{
	t_comand_asm	*new_list;

	if (!(new_list = (t_comand_asm*)malloc(sizeof(t_comand_asm))))
		return (NULL);
	new_list->comand = ft_strdup(line);
	new_list->arg = NULL;
	new_list->num_line = num_line;
	new_list->num_line_for_error = a;
	new_list->for_variables = ft_strdup(for_va);
	new_list->weight = 0;
	new_list->next = NULL;
	new_list->previous = NULL;
	return (new_list);
}
