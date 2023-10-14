/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:48:00 by mryoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:23:26 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_delivery(int sig)
{
	write(1, "Message Delivery Success.", 25);
}

int	ft_atoi(const char *str)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (sign * n);
}

void	send_byte(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(424);
		i--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(str[i], pid);
		i++;
	}
	send_byte(0, pid);
}

int	main(int ac, char *av[])
{
	int		server_pid;
	char	*message;

	signal(SIGUSR2, check_delivery);
	if (ac != 3)
	{
		write(1, "Try ./client [server-pid] [message]\n", 37);
		exit(0);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];
	send_message(message, server_pid);
	return (0);
}
