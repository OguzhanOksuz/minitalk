/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:06:29 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/03/14 04:45:05 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

int		is_pid_correct(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int num);
void	send_bits(int pid, char c);
void	get_bits(int sig);

#endif
