/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tags_and_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:49:37 by sgarry            #+#    #+#             */
/*   Updated: 2019/09/05 18:01:27 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		tags_and_links_1(int i, t_comand_asm *b, t_arg *c)
{
	int			res;

	res = 0;
	while (b && b->num_line <= i)
	{
		res += b->weight;
		if (b->next)
			b = b->next;
		else
			break ;
	}
	if (b->num_line < i)
		return (1);
	if (b->previous)
		b = b->previous;
	if (b->previous && b->num_line == i)
		res -= b->weight;
	c->value = res;
	return (0);
}

void	tags_and_links_2(int i, t_comand_asm *b, t_arg *c)
{
	int res;

	res = 0;
	if (b->previous)
		b = b->previous;
	while (b && b->num_line >= i)
	{
		res -= b->weight;
		b = b->previous;
	}
	c->value = res;
}

void	tags_and_links_3(t_pars_asm *a, t_arg *c)
{
	while (a->link_asm)
	{
		if (!(ft_strcmp(a->link_asm->link_name, c->name_label)))
			break ;
		a->link_asm = a->link_asm->next;
	}
	if (!(a->link_asm))
	{
		ft_putstr("\033[31mNon-existent link\033[m\n");
		free_parse_asm(&a);
		exit(0);
	}
}

void	tags_and_links_4(t_pars_asm *a, t_arg *c, t_comand_asm *b)
{
	if (a->link_asm->num_line - b->num_line > 0)
	{
		if (tags_and_links_1(a->link_asm->num_line, b, c))
		{
			ft_printf("\033[31mNot comand in link\033[m\n");
			free_parse_asm(&a);
			exit(1);
		}
	}
	else
		tags_and_links_2(a->link_asm->num_line, b, c);
}

void	tags_and_links(t_pars_asm *a)
{
	t_comand_asm	*b;
	t_arg			*c;
	t_link_asm		*start;
	t_comand_asm	*start1;

	b = a->comand_asm;
	start = a->link_asm;
	while (b)
	{
		c = b->arg;
		while (c)
		{
			if (c->name_label)
			{
				tags_and_links_3(a, c);
				start1 = b;
				tags_and_links_4(a, c, b);
				a->link_asm = start;
				b = start1;
			}
			c = c->next;
		}
		b = b->next;
	}
}
