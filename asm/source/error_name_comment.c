/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:18:38 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 11:49:54 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	error_in_name_or_comment(t_pars_asm **pars_asm, t_asm **asm_list,
		char *str)
{
	ft_putstr(str);
	while ((*asm_list)->previous)
		(*asm_list) = (*asm_list)->previous;
	free_asm_list(asm_list);
	free_parse_asm(pars_asm);
	exit(1);
}

void	no_code_1(t_pars_asm **pars_asm, t_asm **asm_list, int i)
{
	if (!(*asm_list)->next)
		error_in_name_or_comment(pars_asm, asm_list,
				"\033[31mNo code\033[m\n");
	if ((*asm_list)->one_line[i] == '\"' && (*asm_list)->next)
		*asm_list = (*asm_list)->next;
}

void	error_name(t_pars_asm *pars_asm, t_asm **asm_list, int *flag)
{
	int i;
	int j;

	i = 0;
	while ((*asm_list)->one_line[i] != '\"' && (*asm_list)->one_line[i])
		i++;
	if (!(*asm_list)->one_line[i])
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot name in the file\033[m\n");
	j = 0;
	if ((*asm_list)->one_line[i + 1] == '\"')
		*flag = 1;
	while ((*asm_list)->one_line[++i] != '\"' && j < PROG_NAME_LENGTH)
		if (!(*asm_list)->one_line[i] && (*asm_list)->next)
		{
			*asm_list = (*asm_list)->next;
			i = -1;
		}
		else
			pars_asm->name[j++] = (*asm_list)->one_line[i];
	no_code_1(&pars_asm, asm_list, i);
	if (j == PROG_NAME_LENGTH)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mLength name more than 128\033[m\n");
}

void	error_comment(t_pars_asm *pars_asm, t_asm **asm_list, int *flag)
{
	int i;
	int j;

	i = 0;
	while ((*asm_list)->one_line[i] != '\"' && (*asm_list)->one_line[i])
		i++;
	if (!(*asm_list)->one_line[i])
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot comment in the file\033[m\n");
	j = 0;
	if ((*asm_list)->one_line[i + 1] == '\"')
		*flag = 1;
	while ((*asm_list)->one_line[++i] != '\"' && j < COMMENT_LENGTH)
		if (!(*asm_list)->one_line[i] && (*asm_list)->next)
		{
			*asm_list = (*asm_list)->next;
			i = -1;
		}
		else
			pars_asm->comment[j++] = (*asm_list)->one_line[i];
	no_code_1(&pars_asm, asm_list, i);
	if (j == COMMENT_LENGTH)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mLength comment more than 2048\033[m\n");
}

void	name_and_comment(t_pars_asm *pars_asm, t_asm **asm_list)
{
	int flag;

	flag = 0;
	if (!ft_strncmp((*asm_list)->one_line, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)))
		error_name(pars_asm, asm_list, &flag);
	else if (!ft_strncmp((*asm_list)->one_line,
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		error_comment(pars_asm, asm_list, &flag);
	if (!ft_strncmp((*asm_list)->one_line,
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		error_comment(pars_asm, asm_list, &flag);
	else if (!ft_strncmp((*asm_list)->one_line, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)))
		error_name(pars_asm, asm_list, &flag);
	if (!*pars_asm->name && !*pars_asm->comment && !flag)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot name and comment in file\033[m\n");
	else if (!*pars_asm->name && !flag)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot name in file\033[m\n");
	else if (!*pars_asm->comment && !flag)
		error_in_name_or_comment(&pars_asm, asm_list,
				"\033[31mNot comment in file\033[m\n");
}
