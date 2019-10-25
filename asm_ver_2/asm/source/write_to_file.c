/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:50:26 by sgarry            #+#    #+#             */
/*   Updated: 2019/09/12 08:53:17 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_to_file_1(t_pars_asm *p, int i, int fd)
{
	write_bytes(fd, COREWAR_EXEC_MAGIC, 4);
	while (p->name[i])
	{
		write_bytes(fd, p->name[i], 1);
		i++;
	}
	while (i != 132)
	{
		write_bytes(fd, 0, 1);
		i++;
	}
	write_bytes(fd, size_code(p->comand_asm), 4);
	i = 0;
	while (p->comment[i])
	{
		write_bytes(fd, p->comment[i], 1);
		i++;
	}
	while (i != 2052)
	{
		write_bytes(fd, 0, 1);
		i++;
	}
}

void	write_to_file_3(t_pars_asm *p, int i, unsigned char op, int fd)
{
	t_arg *start;

	start = p->comand_asm->arg;
	while (p->comand_asm->arg)
	{
		code_comment(i, p->comand_asm->arg->arg_type, &op);
		i++;
		p->comand_asm->arg = p->comand_asm->arg->next;
	}
	write_bytes(fd, op, 1);
	p->comand_asm->arg = start;
}

void	write_to_file(t_pars_asm *p, char *str, int i)
{
	int				f;
	t_arg			*start;
	int				com;
	unsigned char	op;

	f = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write_to_file_1(p, 0, f);
	while (p->comand_asm)
	{
		i = 0;
		op = 0;
		com = check_valid_comand(p->comand_asm->comand);
		write_bytes(f, g_operations[com].opcode, 1);
		if (g_operations[com].codage)
			write_to_file_3(p, i, op, f);
		start = p->comand_asm->arg;
		while (p->comand_asm->arg)
		{
			write_bytes(f, p->comand_asm->arg->value, p->comand_asm->arg->size);
			p->comand_asm->arg = p->comand_asm->arg->next;
		}
		p->comand_asm->arg = start;
		p->comand_asm = p->comand_asm->next;
	}
	ft_printf("{green}Your fighter is written to the file: %s{eoc}\n", str);
}

void	ft_weight(t_comand_asm *a)
{
	t_arg *start;

	while (a)
	{
		if (g_operations[check_valid_comand(a->comand)].codage)
			a->weight = 2;
		else
			a->weight = 1;
		start = a->arg;
		while (a->arg)
		{
			a->weight += a->arg->size;
			a->arg = a->arg->next;
		}
		a->arg = start;
		a = a->next;
	}
}
