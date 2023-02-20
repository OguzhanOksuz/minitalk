/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:23:10 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/02/20 23:24:30 by Ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_alnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	np;

	num = 0;
	if (*str == '-')
	{
		np = -1;
		str++;
	}
	else
		np = 1;
	while (*str >= '0' && *str <= '9')
	{
		num = (10 * num) + (*str - '0');
		str++;
	}
	return (num * np);
}

void	send_bits(int pid, char c)
{
	int	i;

	i = 8;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	char	*msg;

	if (ac == 3)
	{
		if (is_alnum(av[1]))
		{
			pid = ft_atoi(av[1]);
			msg = av[2];
			while (*msg)
			{
				send_bits(pid, *msg);
				msg++;
			}
		}
		else
			write(2, "Error\n", 6); 
	}
	else
		write(2, "Error\n", 6); 
}
