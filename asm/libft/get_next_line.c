/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 00:11:24 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/19 13:42:20 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	str(t_gnl *list, size_t i, char **line)
{
	if (!list)
	{
		*line = ft_strnew(i);
		return ;
	}
	str(list->next, i + list->content_size, line);
	ft_strncat(*line, list->content, list->content_size);
}

static	int		w_and_cr_list(const int fd, t_gnl **list, int i)
{
	char	str[BUFF_SIZE];
	int		rad;
	t_gnl	*new_str;

	while ((rad = read(fd, str, BUFF_SIZE)))
	{
		if (rad < 0)
			return (rad);
		new_str = ft_lstnew(str, rad);
		ft_lstadd(list, new_str);
		i = 0;
		while (i < rad)
		{
			if (str[i] == '\n')
				return (rad);
			i++;
		}
	}
	return (rad);
}

static	void	ft_free_list(t_gnl **list)
{
	if (!*list || !list)
		return ;
	ft_free_list(&(*list)->next);
	if ((*list)->content)
	{
		free((*list)->content);
		(*list)->content = NULL;
	}
	free(*list);
	*list = NULL;
}

static	void	w_in_line(char **line, t_gnl **list, size_t i)
{
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	(*line)[i] = '\0';
	if ((*line)[i + 1])
	{
		ft_free_list(list);
		*list = ft_lstnew(&(*line)[i + 1], ft_strlen(&(*line)[i + 1]));
	}
	else
		ft_free_list(list);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*s_list[10240];
	int				rad;

	if (fd < 0 || line == NULL)
		return (-1);
	if (s_list[fd] == NULL)
	{
		rad = w_and_cr_list(fd, &s_list[fd], 0);
		str(s_list[fd], 0, line);
		if (rad == 0 && s_list[fd] == NULL)
			return (0);
		if (rad < 0)
			return (-1);
		w_in_line(line, &s_list[fd], 0);
		return (1);
	}
	w_and_cr_list(fd, &s_list[fd], 0);
	str(s_list[fd], 0, line);
	w_in_line(line, &s_list[fd], 0);
	return (1);
}
