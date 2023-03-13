/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:23:10 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/03/13 10:17:45 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	char	*msg;
	int	i;

	i = 0;
	if (ac == 3)
	{
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
