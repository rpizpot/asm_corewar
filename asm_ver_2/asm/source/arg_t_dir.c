/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_t_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:02:53 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:11 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_valid_arg_t_dir_num_or_link(char **arg, t_pars_asm *pars_asm,
		t_asm *asm_link, int i)
{
	int j;

	j = (arg[i][1] == LABEL_CHAR) ? 1 : 0;
	if (j == 1)
		while (arg[i][++j])
			if (!(ft_strchr(LABEL_CHARS, arg[i][j])))
			{
				ft_printf("{red}Not valid link: \n%i. %s %s <--{eoc}\n",
						pars_asm->comand_asm->num_line_for_error,
						pars_asm->comand_asm->comand, arg[i]);
				del_arg(arg);
				free_all(&pars_asm, &asm_link);
			}
	if (j == 0)
		while (arg[i][++j])
			if (!(ft_strchr(LABEL_NUMS, arg[i][j])))
			{
				ft_printf("{red}Not valid value: \n%i. %s %s <--{eoc}\n",
						pars_asm->comand_asm->num_line_for_error,
						pars_asm->comand_asm->comand, arg[i]);
				del_arg(arg);
				free_all(&pars_asm, &asm_link);
			}
}

void	check_valid_arg_t_dir(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		int i)
{
	if ((arg[i][1] == LABEL_CHAR && !arg[i][2]) || !arg[i][1])
	{
		if (!arg[i][1])
			ft_printf("{red}Not valid value: \n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand);
		else
			ft_printf("{red}Not valid link: \n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand);
		del_arg(arg);
		free_all(&pars_asm, &asm_link);
	}
	check_valid_arg_t_dir_num_or_link(arg, pars_asm, asm_link, i);
}

t_arg	*new_arg_t_dir(t_arg *all_arg, char *str, int comand)
{
	t_arg *com_arg;

	if (!(com_arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	com_arg->size = g_operations[comand].label_size;
	if (str[1] == LABEL_CHAR)
	{
		com_arg->name_label = ft_strdup(&(str[2]));
		com_arg->value = 0;
	}
	else
	{
		com_arg->name_label = NULL;
		com_arg->value = ft_atoi(&str[1]);
	}
	com_arg->arg_type = 2;
	com_arg->next = NULL;
	all_arg = add_arg_back(all_arg, com_arg);
	return (all_arg);
}

t_arg	*arg_t_dir(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		t_arg *all_arg)
{
	int		i;
	t_arg	*start;

	i = 0;
	start = all_arg;
	while (all_arg)
	{
		all_arg = all_arg->next;
		i++;
	}
	all_arg = start;
	check_valid_arg_t_dir(arg, pars_asm, asm_link, i);
	if (!(all_arg = new_arg_t_dir(all_arg, arg[i],
			check_valid_comand(pars_asm->comand_asm->comand))))
	{
		free_all(&pars_asm, &asm_link);
		del_arg(arg);
	}
	return (all_arg);
}
