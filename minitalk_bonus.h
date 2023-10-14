/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:37:59 by mryoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:22:55 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	c;
	int		client_pid;
}	t_data;

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	check_delivery(int sig);
void	init_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);
#endif
