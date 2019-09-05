/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clist_find_prev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:37:52 by sgarry            #+#    #+#             */
/*   Updated: 2019/09/05 11:37:53 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lists	*ft_clist_find_prev(t_lists *wall)
{
	t_lists	*list;

	if (!wall || !wall->next)
		return (NULL);
	list = wall->next;
	while (list->next != wall)
		list = list->next;
	return (list);
}
