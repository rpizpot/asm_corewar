/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cod_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:29:57 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/23 19:29:57 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	read_cod_asm(int fd, t_asm **asm_list, int num_line)
{
	char	*line;
	t_asm	*new_asm_list;
	int		i;

	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("\0", line))
			ft_strdel(&line);
		else
		{
			i = 0;
			while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\f' || line[i] == '\r')
				i++;
			if (line[i])
			{
				new_asm_list = new_list_asm((line + i), num_line);
				(*asm_list) = add_alist_back((*asm_list), new_asm_list);
				num_line++;
			}
			ft_strdel(&line);
		}
	}
	return (0);
}