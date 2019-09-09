/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:00:07 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:57:07 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_asm	*new_list_asm(char *line, int num_line, int a)
{
	t_asm *new_alist;

	if (!(new_alist = (t_asm *)malloc(sizeof(t_asm))))
		return (NULL);
	if (!(new_alist->one_line = ft_strdup(line)))
		return (NULL);
	new_alist->line_num = num_line;
	new_alist->num_line_for_error = a;
	new_alist->next = NULL;
	new_alist->previous = NULL;
	return (new_alist);
}
