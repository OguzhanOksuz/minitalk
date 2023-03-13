/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:05:17 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/13 09:49:00 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_pid_correct(char *str)
{
	int	i;

	i = 0;
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
	unsigned int num;
	int		i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	return (num);
}

void	ft_putnbr(int num)
{
	char	c;
	
	if (num >= 10)
		ft_putnbr(num / 10);
	c = 48 + (num % 10);
	write(1, &c, 1);
}

