/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:32 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/03/14 15:35:07 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits_bonus(int sig, siginfo_t *info, void *oldact)
{
	static int	bit = 7;
	static int	c = 0;

	if (sig == SIGUSR1)
		c += 1 << bit;
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		bit = 7;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	(void)oldact;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_bits_bonus;
	sig.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
