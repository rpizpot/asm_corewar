/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_t_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:40:04 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:18 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_error_t_reg(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		int i)
{
	ft_printf("{red}Invalid register name:\n%i. %s %s <--{eoc}\n",
			pars_asm->comand_asm->num_line_for_error,
			pars_asm->comand_asm->comand, arg[i]);
	del_arg(arg);
	free_all(&pars_asm, &asm_link);
}

t_arg	*new_arg_t_reg(t_arg *all_arg, char *str)
{
	t_arg *com_arg;

	if (!(com_arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	com_arg->size = 1;
	com_arg->value = ft_atoi(&str[1]);
	com_arg->name_label = NULL;
	com_arg->arg_type = 1;
	com_arg->next = NULL;
	all_arg = add_arg_back(all_arg, com_arg);
	return (all_arg);
}

t_arg	*arg_t_reg(char **arg, t_pars_asm *pars_asm, t_asm *asm_link,
		t_arg *all_arg)
{
	int		j;
	int		i;
	t_arg	*start;

	i = 0;
	j = 0;
	start = all_arg;
	while (all_arg)
	{
		all_arg = all_arg->next;
		i++;
	}
	all_arg = start;
	if (!arg[i][1])
		print_error_t_reg(arg, pars_asm, asm_link, i);
	while (arg[i][++j])
		if (!ft_strchr(ALL_NUM, arg[i][j]))
			print_error_t_reg(arg, pars_asm, asm_link, i);
	if (!(all_arg = new_arg_t_reg(all_arg, arg[i])))
	{
		del_arg(arg);
		free_all(&pars_asm, &asm_link);
	}
	return (all_arg);
}
