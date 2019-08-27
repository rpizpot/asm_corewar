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
	char *colon;
	char *percent;
	char *comma;
	int i;
	int j;
	char *check;
	t_link_asm *link_asm;
	t_comand_asm *comand_asm;

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
		asm_list = asm_list->next;
	while (asm_list)
	{
		colon = ft_strchr(asm_list->one_line, ':');
		percent = ft_strchr(asm_list->one_line, '%');
		comma = ft_strchr(asm_list->one_line, ',');
		if ()
		{
			link_asm = link_asm_new_list(asm_list->one_line,
					asm_list->line_num, (colon - asm_list->one_line));
			pars_asm->link_asm = add_new_link_list(pars_asm->link_asm,
					link_asm);
		}
		else if ((percent && !colon && !comma) || (colon && percent < colon)
		|| (!colon && comma))
		{
			check = ft_strnew(5);
			i = 0;
			while (asm_list->one_line[i] != '%' && asm_list->one_line[i] != ' '
			&& i < 5)
			{
				check[i] = asm_list->one_line[i];
				i++;
			}
			if (!check_valid_comand(check))
			{
				comand_asm = comand_asm_new_list(check,
						asm_list->line_num);
				pars_asm->comand_asm = add_new_comand_asm_list(
						pars_asm->comand_asm,
						comand_asm);
			}
			else
				return (0); //в будущем нужно free - шить весь лист pars_asm
			ft_strdel(&check);
		}
		else if (((percent || comma) && colon) && ((percent > colon) || (comma > colon)))
		{
			j = colon - asm_list->one_line;
			link_asm = link_asm_new_list(asm_list->one_line,
					asm_list->line_num, j);
			pars_asm->link_asm = add_new_link_list(pars_asm->link_asm,
					link_asm);
			j++;
			while (asm_list->one_line[j] == ' '|| asm_list->one_line[j] == '\t'
			|| asm_list->one_line[j] == '\v' || asm_list->one_line[j] == '\f'
			|| asm_list->one_line[j] == '\r')
				j++;
			check = ft_strnew(5);
			i = 0;
			while (asm_list->one_line[j] != '%' && asm_list->one_line[j] != ' '
					&& (asm_list->one_line[j] <= '0' || asm_list->one_line[j] >= '9')
					&& i < 5)
			{
				check[i] = asm_list->one_line[j];
				i++;
				j++;
			}
			if (!check_valid_comand(check) && (asm_list->one_line[j] >= '0'
					&& asm_list->one_line[j] <= '9'))
				return (0); //в будущем нужно free - шить весь лист pars_asm
			else if (asm_list->one_line[j] >= '0' && asm_list->one_line[j] <= '9')
				check[i - 1] = '\0';
			if (!check_valid_comand(check))
			{
				comand_asm = comand_asm_new_list(check,
						asm_list->line_num);
				pars_asm->comand_asm = add_new_comand_asm_list(
						pars_asm->comand_asm,
						comand_asm);
			}
			else
				return (0);  //в будущем нужно free - шить весь лист pars_asm
			ft_strdel(&check);
			ft_strdel(&check);
		}
		else
			return (0); //в будущем нужно free - шить весь лист pars_asm*/
		asm_list = asm_list->next;
	}
	printf("%s\n", pars_asm->name);
	printf("%s\n", pars_asm->comment);
	//printf("%s\n", pars_asm->comand_asm->comand);
	return (0);
}