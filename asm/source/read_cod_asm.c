/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cod_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:29:57 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:57:33 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	skip_space(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	read_cod_asm(int fd, t_asm **asm_list, int num_line, int a)
{
	char	*line;
	t_asm	*new_asm_list;
	int		i;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("\0", line))
			a++;
		else
		{
			i = skip_space(line);
			if (line[i] != '#' && line[i] != ';' && line[i])
			{
				a++;
				new_asm_list = new_list_asm((line + i), num_line, a);
				(*asm_list) = add_alist_back((*asm_list), new_asm_list);
				num_line++;
			}
			else
				a++;
		}
		ft_strdel(&line);
	}
	return (0);
}
