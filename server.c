/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:32:31 by mryoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:23:05 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	init_data(void)
{
	g_data.i = 0;
	g_data.c = 0;
	g_data.client_pid = 0;
}

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		init_data();
	g_data.c = g_data.c << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		write(1, &g_data.c, 1);
		init_data();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	init_data();
	write(1, "server-pid: ", 13);
	ft_putnbr(getpid());
	write(1, "\n", 2);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
