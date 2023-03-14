/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:23:10 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/03/14 15:39:21 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_send(int sig)
{
	write(1, "Signal send correctly\n", 22);
	(void)sig;
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	i = 0;
	if (ac == 3)
	{
		signal(SIGUSR1, msg_send);
		if (is_pid_correct(av[1]))
		{
			pid = ft_atoi(av[1]);
			msg = av[2];
			while (msg[i])
			{
				send_bits(pid, msg[i]);
				i++;
			}
		}
		else
			write(2, "Wrong PID\n", 10);
	}
	else
		write(2, "Invalid args\n", 13);
	return (0);
}
