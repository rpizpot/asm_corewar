/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:48:39 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 11:36:55 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	no_code(t_pars_asm *pars_asm, t_asm *asm_list_start)
{
	ft_putstr("\033[31mNo code\033[m\n");
	free_asm_list(&asm_list_start);
	ft_strdel(&pars_asm->name);
	ft_strdel(&pars_asm->comment);
	free(pars_asm);
	pars_asm = NULL;
	exit(0);
}

void	main_2(t_asm *l, t_pars_asm *pars_asm, t_asm *asm_list_start, char **av)
{
	while (l)
	{
		l->one_line = replace(l->one_line, ';', '#');
		parse_one_line(pars_asm, l, l->one_line);
		l = l->next;
	}
	check_valid_link(pars_asm);
	parse_variables(pars_asm, asm_list_start);
	while (asm_list_start->previous)
		asm_list_start = asm_list_start->previous;
	free_asm_list(&asm_list_start);
	ft_weight(pars_asm->comand_asm);
	tags_and_links(pars_asm);
	write_to_file(pars_asm, replacement(av[1]));
	free_asm_list(&asm_list_start);
	free_parse_asm(&pars_asm);
}

int		main(int ac, char **av)
{
	int			fd;
	t_asm		*asm_list;
	t_pars_asm	*pars_asm;
	t_asm		*asm_list_start;

	if (ac != 2)
		return (ft_putstr("\033[31mWrong number of arguments\033[m\n"));
	ft_check_file(av[1]);
	asm_list = NULL;
	if (!(pars_asm = (t_pars_asm *)malloc(sizeof(t_pars_asm))))
		return (0);
	fd = open(av[1], O_RDONLY);
	read_cod_asm(fd, &asm_list, 1, 0);
	if (!asm_list)
		return (ft_putstr("\033[31mNo code\033[m\n"));
	asm_list_start = asm_list;
	inicializ_corewar(pars_asm);
	name_and_comment(pars_asm, &asm_list);
	if (!(asm_list->next))
		no_code(pars_asm, asm_list_start);
	main_2(asm_list, pars_asm, asm_list_start, av);
	return (0);
}
