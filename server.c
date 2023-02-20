/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:32 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/02/20 23:30:33 by Ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits(int sig)
{
	static char	c = 0;
	static int	bit = 8;

	if (sig == 1)
		c += 1 << bit;
	bit--;
	if (bit == 0)
	{
		write(1, &c, 1);
		bit = 8;
		c = 0;
	}
}

void	move_bit(void)
{
	get_bits(0);
}

void	inc_bit(void)
{
	get_bits(1);
}

void	ft_putnbr(int num)
{
	char	c;
	
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	c = 48 + (num % 10);
	write(1, &c, 1);
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, inc_bit());
		signal(SIGUSR2, move_bit());
	}
}

