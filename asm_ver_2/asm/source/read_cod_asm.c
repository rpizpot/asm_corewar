/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cod_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:29:57 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/12 10:46:55 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	read_cod_asm(int fd, t_asm **asm_list, int num_line, int a)
{
	char	*line;
	t_asm	*new_asm_list;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		a++;
		new_asm_list = new_list_asm(line, num_line, a);
		(*asm_list) = add_alist_back((*asm_list), new_asm_list);
		num_line++;
		ft_strdel(&line);
	}
	return (0);
}
