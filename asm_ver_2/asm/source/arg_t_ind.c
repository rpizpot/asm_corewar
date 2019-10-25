/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_t_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:09:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:15 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_valid_arg_t_ind_num_or_link(char **arg, t_pars_asm *pars_asm,
		t_asm *asm_link, int i)
{
	int j;

	j = (arg[i][0] == LABEL_CHAR) ? 0 : -1;
	if (j == 0)
		while (arg[i][++j])
			if (!(ft_strchr(LABEL_CHARS, arg[i][j])))
			{
				ft_printf("{red}Not valid link: \n%i. %s %s <--{eoc}\n",
						pars_asm->comand_asm->num_line_for_error,
						pars_asm->comand_asm->comand, arg[i]);
				del_arg(arg);
				free_all(&pars_asm, &asm_link);
			}
	if (j == -1)
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

void	check_valid_arg_t_ind(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		int i)
{
	if (arg[i][0] == LABEL_CHAR && !arg[i][1])
	{
		ft_printf("{red}Not valid link: \n%i. %s %s <--{eoc}\n",
				pars_asm->comand_asm->num_line_for_error,
				pars_asm->comand_asm->comand, arg[i]);
		del_arg(arg);
		free_all(&pars_asm, &asm_link);
	}
}

t_arg	*new_arg_t_ind(t_arg *all_arg, char *str)
{
	t_arg *com_arg;

	if (!(com_arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	com_arg->size = IND_SIZE;
	if (str[0] == LABEL_CHAR)
	{
		com_arg->name_label = ft_strdup(&str[1]);
		com_arg->value = 0;
	}
	else if (ft_isdigit(str[0]) || (str[0] == '-' && ft_isdigit(str[1])))
	{
		com_arg->name_label = NULL;
		com_arg->value = ft_atoi(&str[0]);
	}
	com_arg->arg_type = 3;
	com_arg->next = NULL;
	all_arg = add_arg_back(all_arg, com_arg);
	return (all_arg);
}

t_arg	*arg_t_ind(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
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
	check_valid_arg_t_ind(arg, pars_asm, asm_link, i);
	check_valid_arg_t_ind_num_or_link(arg, pars_asm, asm_link, i);
	if (!(all_arg = new_arg_t_ind(all_arg, arg[i])))
	{
		free_all(&pars_asm, &asm_link);
		del_arg(arg);
	}
	return (all_arg);
}
