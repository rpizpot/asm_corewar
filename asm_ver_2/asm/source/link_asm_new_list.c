/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_asm_new_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:15:24 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/12 09:44:17 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_link_asm	*link_asm_new_list(char *line, int num_line, int len, int a)
{
	t_link_asm	*new_list;
	int			i;

	i = -1;
	if (!(new_list = (t_link_asm*)malloc(sizeof(t_link_asm))))
		return (NULL);
	new_list->link_name = ft_strnew(len);
	while (++i < len)
		new_list->link_name[i] = line[i];
	new_list->num_line = num_line;
	new_list->num_line_for_error = a;
	new_list->next = NULL;
	new_list->previous = NULL;
	return (new_list);
}
