/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:09:50 by mryoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:23:02 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
void	ft_putnbr(int fd);
void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	init_data(void);
void	handler(int sig, siginfo_t *info, void *context);

#endif
