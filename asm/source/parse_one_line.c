/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:47:43 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:57:24 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	new_mark(t_pars_asm *pars_asm, t_asm *asm_list, char **check,
		char **for_link)
{
	t_link_asm *link_asm;

	link_asm = link_asm_new_list(asm_list->one_line,
			asm_list->line_num, ((*check) - asm_list->one_line),
			asm_list->num_line_for_error);
	pars_asm->link_asm = add_new_link_list(pars_asm->link_asm,
			link_asm);
	(*check)++;
	while ((**check) == ' ' || (**check) == '\t')
		(*check)++;
	(*for_link) = (*check);
}

void	new_comand(t_pars_asm *pars_asm, t_asm *asm_list, char **check,
		char **for_link)
{
	char			*str;
	int				i;
	t_comand_asm	*comand_asm;

	str = ft_strnew(5);
	i = 0;
	if (!(*for_link))
		(*for_link) = asm_list->one_line;
	while ((**for_link) != '%' && (**for_link) != ' ' && (**for_link) != '\t'
	&& i < 5)
	{
		str[i++] = (**for_link);
		(*for_link)++;
	}
	comand_asm = comand_asm_new_list(str,
			asm_list->line_num, (*check), asm_list->num_line_for_error);
	pars_asm->comand_asm = add_new_comand_asm_list(
			pars_asm->comand_asm, comand_asm);
	ft_strdel(&str);
	*check = *for_link;
}

void	print_error(char *for_link, t_pars_asm *pars_asm, t_asm *asm_list,
		int i)
{
	if (i == 0)
	{
		for_link = ft_itoa(pars_asm->link_asm->num_line_for_error);
		ft_printf("{red}Second label in line:\n%s. \"%s\"{eoc}\n", for_link,
				asm_list->one_line);
		ft_strdel(&for_link);
		free_all(&pars_asm, &asm_list);
		exit(1);
	}
	else if (i == 1)
	{
		ft_printf("{red}Not label  and comand in line:\n\"%s\"{eoc}\n",
				asm_list->one_line);
		free_all(&pars_asm, &asm_list);
		exit(1);
	}
}

void	parse_one_line(t_pars_asm *pars_asm, t_asm *asm_list, char *check)
{
	char	*for_link;
	char	*for_comand;

	for_link = NULL;
	for_comand = NULL;
	while (*check)
	{
		if (*check == LABEL_CHAR && !for_link)
			new_mark(pars_asm, asm_list, &check, &for_link);
		else if ((*check == DIRECT_CHAR || *check == ' ' || *check == '\t')
		&& !for_comand)
		{
			new_comand(pars_asm, asm_list, &check, &for_link);
			for_comand = check;
		}
		if (*check == LABEL_CHAR && for_link && !for_comand)
			print_error(for_link, pars_asm, asm_list, 0);
		if (*check)
			check++;
	}
	if (!for_link && !for_comand)
		print_error(for_link, pars_asm, asm_list, 1);
}
