/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 07:56:24 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/08 08:39:45 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int number;

	number = n;
	if (number < 0)
	{
		number *= -1;
		ft_putchar('-');
	}
	if (number / 10 > 0)
		ft_putnbr(number / 10);
	ft_putchar(number % 10 + '0');
}
