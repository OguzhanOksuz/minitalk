/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:32 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/03/13 10:20:13 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits(int sig, siginfo_t *info, void *con)
{
	static int	c = 0;
	static int	bit = 7;

	if (sig == SIGUSR1)
		c += 1 << bit;
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		bit = 7;
		c = 0;
	}
	(void) info;
	(void) con;
}

int	main(void)
{
	struct sigaction sig;

	sig.sa_sigaction = get_bits;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}

