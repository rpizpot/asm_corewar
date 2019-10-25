/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:46:55 by rpizpot           #+#    #+#             */
/*   Updated: 2019/09/05 10:57:17 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_arg	*pars_arg(char **arg, t_pars_asm *pars_asm, t_asm *asm_link)
{
	t_arg	*all_arg;
	int		i;
	int		valid;

	all_arg = NULL;
	i = -1;
	while (arg[++i])
	{
		arg[i][0] == DIRECT_CHAR ? valid = T_DIR : -1;
		arg[i][0] == 'r' ? valid = T_REG : -1;
		ft_isdigit(arg[i][0]) || (arg[i][0] == '-' && ft_isdigit(arg[i][1]))
				|| arg[i][0] == LABEL_CHAR ? valid = T_IND : -1;
		if (valid == T_DIR)
			all_arg = arg_t_dir(arg, pars_asm, asm_link, all_arg);
		else if (valid == T_REG)
			all_arg = arg_t_reg(arg, pars_asm, asm_link, all_arg);
		else if (valid == T_IND)
			all_arg = arg_t_ind(arg, pars_asm, asm_link, all_arg);
	}
	return (all_arg);
}
