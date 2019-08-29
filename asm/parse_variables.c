/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:10:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/27 17:10:03 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_variables(t_pars_asm *pars_asm)
{
	int		i;
	int		j;
	char	**arg;
	int		valid;
	t_arg	*com_arg;
	t_arg	*all_arg;
	t_comand_asm *start;

	start = pars_asm->comand_asm;
	valid = -1;
	while(pars_asm->comand_asm)
	{
		i = 0;
		if ((j = check_valid_comand(pars_asm->comand_asm->comand))== -1)
			break ;
		arg = str_split_arg(pars_asm->comand_asm->for_variables);
		all_arg = NULL;
		while (arg[i])
		{
			arg[i][0] == DIRECT_CHAR ? valid = T_DIR : -1;
			arg[i][0] == 'r' ? valid = T_REG : -1;
			(arg[i][0] == LABEL_CHAR || ft_isdigit(arg[i])) ? valid = T_IND
					: -1;
			if (valid == T_DIR)
			{
				com_arg = (t_arg *)malloc(sizeof(t_arg));
				com_arg->size = g_operations[j].label_size;
				if (arg[i][1] == LABEL_CHAR)
				{
					com_arg->name_label = ft_strdup(&(arg[i][2]));
					com_arg->value = 0;
				}
				else
				{
					com_arg->name_label = 0;
					com_arg->value = ft_atoi(&arg[i][1]);
				}
				com_arg->arg_type = 1;
				com_arg->next = NULL;
				all_arg = add_arg_back(all_arg, com_arg);
			}
			else if (valid == T_REG)
			{
				com_arg = (t_arg *)malloc(sizeof(t_arg));
				com_arg->size = 1;
				com_arg->value = ft_atoi(&arg[i][1]);
				com_arg->name_label = 0;
				com_arg->arg_type = 2;
				com_arg->next = NULL;
				all_arg = add_arg_back(all_arg, com_arg);
			}
			else if (valid == T_IND)
			{
				com_arg = (t_arg *)malloc(sizeof(t_arg));
				com_arg->size = IND_SIZE;
				if (arg[i][0] == LABEL_CHAR)
				{
					com_arg->name_label = ft_strdup(&(arg[i][1]));
					com_arg->value = 0;
				}
				else if (ft_isdigit(arg[i]))
				{
					com_arg->name_label = 0;
					com_arg->value = ft_atoi(&arg[i][0]);
				}
				com_arg->arg_type = 3;
				com_arg->next = NULL;
				all_arg =  add_arg_back(all_arg, com_arg);
			}
			i++;
		}
		pars_asm->comand_asm->arg = all_arg;
		pars_asm->comand_asm = pars_asm->comand_asm->next;
	}
	pars_asm->comand_asm = start;
}