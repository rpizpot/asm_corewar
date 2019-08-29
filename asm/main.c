/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:48:39 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/23 18:48:39 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	t_asm *asm_list;
	t_pars_asm *pars_asm;
	char *error;
	char *binary_code;

	asm_list = NULL;
	pars_asm = (t_pars_asm *)malloc(sizeof(t_pars_asm));
	fd = open(av[1], O_RDONLY);
	read_cod_asm(fd, &asm_list, 1);
	inicializ_corewar(pars_asm);
	while (ft_strncmp(asm_list->one_line, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)))
		asm_list = asm_list->next;
	if ((error = error_name(pars_asm, asm_list)))
		ft_printf("%s", error);
	while (asm_list->previous)
		asm_list = asm_list->previous;
	while (ft_strncmp(asm_list->one_line, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)))
		asm_list = asm_list->next;
	if ((error = error_comment(pars_asm, asm_list)))
		ft_printf("%s", error);
	if (asm_list->next)
		asm_list = asm_list->next;;
	while (asm_list)
	{
		parse_one_line(pars_asm, asm_list, asm_list->one_line);
		asm_list = asm_list->next;
	}
	parse_variables(pars_asm);
	binary_code = ft_memalloc(BUFF_SIZE_ASM);

	printf("%s\n", pars_asm->name);
	printf("%s\n", pars_asm->comment);
	return (0);
}