/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:44:29 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/09 22:27:02 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstnew(void const *content, size_t content_size)
{
	t_gnl *new_list;

	new_list = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new_list)
		return (NULL);
	if (!content)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
		return (new_list);
	}
	new_list->content = (void *)malloc(content_size);
	if (!new_list->content)
	{
		free(new_list);
		return (NULL);
	}
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	new_list->next = NULL;
	return (new_list);
}
