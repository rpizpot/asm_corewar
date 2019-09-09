/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:20:52 by sgarry            #+#    #+#             */
/*   Updated: 2019/09/04 13:00:17 by sgarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_bytes(int fd, int a, int count_bytes)
{
	int				j;
	unsigned char	mass[count_bytes];

	j = count_bytes;
	while (count_bytes--)
	{
		mass[count_bytes] = (unsigned char)a;
		a >>= 8;
	}
	while (++count_bytes < j)
		write(fd, &mass[count_bytes], 1);
}

int		size_code(t_comand_asm *c)
{
	int summ;

	summ = 0;
	while (c)
	{
		summ += c->weight;
		c = c->next;
	}
	return (summ);
}

void	code_comment(int index, unsigned char type, unsigned char *op)
{
	if (index == 0)
		(*op) |= type << 6;
	else if (index == 1)
		*op |= type << 4;
	else if (index == 2)
		*op |= type << 2;
}

void	ft_check_file(char *str)
{
	while (*str)
		++str;
	if (*(str - 1) != 's' || *(str - 2) != '.')
	{
		ft_putstr("\033[31mInvalid file format\033[m\n");
		exit(0);
	}
}

char	*replacement(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = ft_strnew(ft_strlen(str) + 2);
	ft_strcpy(str1, str);
	while (str1[i])
		++i;
	str1[i - 1] = 'c';
	str1[i] = 'o';
	str1[i + 1] = 'r';
	return (str1);
}
