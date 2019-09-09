/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:57:12 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:28 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_valid_link(t_pars_asm *pars_asm)
{
	int			i;
	t_link_asm	*link_asm;
	t_link_asm	*start;

	link_asm = pars_asm->link_asm;
	start = link_asm;
	while (link_asm)
	{
		i = -1;
		while (link_asm->link_name[++i])
			if (!ft_strchr(LABEL_CHARS, link_asm->link_name[i]))
			{
				pars_asm->link_asm = start;
				ft_putstr("Not valid mark: ");
				ft_putstr(link_asm->link_name);
				ft_putstr(" in line ");
				ft_putstr(ft_itoa(link_asm->num_line_for_error));
				ft_putchar('\n');
				free_parse_asm(&pars_asm);
				exit(1);
			}
		link_asm = link_asm->next;
	}
}
