/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:10:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:57:29 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	del_arg(char **arg)
{
	int i;

	i = -1;
	while (arg[++i])
		ft_strdel(&arg[i]);
	free(arg);
}

int		valid_type_arg(int comand, int index, int type)
{
	if (g_operations[comand].args[index] == 3)
		return ((type == T_REG || type == T_DIR) ? 1 : 0);
	if (g_operations[comand].args[index] == 5)
		return ((type == T_REG || type == T_IND) ? 1 : 0);
	if (g_operations[comand].args[index] == 6)
		return ((type == T_DIR || type == T_IND) ? 1 : 0);
	if (g_operations[comand].args[index] == 7)
		return ((type == T_DIR || type == T_IND || type == T_REG) ? 1 : 0);
	if (g_operations[comand].args[index] == 1)
		return ((type == T_REG) ? 1 : 0);
	if (g_operations[comand].args[index] == 2)
		return ((type == T_DIR) ? 1 : 0);
	if (g_operations[comand].args[index] == 4)
		return ((type == T_IND) ? 1 : 0);
	return (0);
}

void	check_type_arg(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		t_comand_asm *start)
{
	int			i;
	int			valid;

	i = -1;
	while (arg[++i])
	{
		valid = -1;
		arg[i][0] == DIRECT_CHAR ? valid = T_DIR : -1;
		arg[i][0] == 'r' ? valid = T_REG : -1;
		ft_isdigit(arg[i][0]) || (arg[i][0] == '-' && ft_isdigit(arg[i][1]))
				|| arg[i][0] == LABEL_CHAR ? valid = T_IND : -1;
		if (!valid_type_arg(check_valid_comand(pars_asm->comand_asm->comand),
				i, valid))
		{
			ft_printf("{red}Not right type of arg:\n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand, arg[i]);
			pars_asm->comand_asm = start;
			del_arg(arg);
			free_all(&pars_asm, &asm_link);
			exit(1);
		}
	}
}

void	print_error_quantity_arg(char **arg, t_pars_asm *pars_asm,
		t_asm *asm_link, t_comand_asm *start)
{
	int i;
	int j;

	i = 0;
	while (arg[i])
		i++;
	j = check_valid_comand(pars_asm->comand_asm->comand);
	if ((g_operations[j].count_args != i))
	{
		if (g_operations[j].count_args < i)
			ft_printf("{red}More arg: \n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand);
		else
			ft_printf("{red}Not enough arg: \n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand);
		pars_asm->comand_asm = start;
		free_all(&pars_asm, &asm_link);
		del_arg(arg);
		exit(1);
	}
}

void	parse_variables(t_pars_asm *pars_asm, t_asm *asm_link)
{
	char			**arg;
	t_comand_asm	*start;

	start = pars_asm->comand_asm;
	while (pars_asm->comand_asm)
	{
		if ((check_valid_comand(pars_asm->comand_asm->comand)) == -1)
		{
			ft_printf("{red}Not right comand: \n%i. %s <--{eoc}\n",
					pars_asm->comand_asm->num_line_for_error,
					pars_asm->comand_asm->comand);
			pars_asm->comand_asm = start;
			free_all(&pars_asm, &asm_link);
			exit(1);
		}
		arg = str_split_arg(pars_asm->comand_asm->for_variables);
		print_error_quantity_arg(arg, pars_asm, asm_link, start);
		check_type_arg(arg, pars_asm, asm_link, start);
		pars_asm->comand_asm->arg = pars_arg(arg, pars_asm, asm_link);
		del_arg(arg);
		pars_asm->comand_asm = pars_asm->comand_asm->next;
	}
	pars_asm->comand_asm = start;
}
