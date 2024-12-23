/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <rcorlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:55:15 by rcorlett          #+#    #+#             */
/*   Updated: 2024/12/23 14:14:39 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_sig_handle(int signal)
{
	static int	bit;
	static char	ch;

	if (!ch)
		ch = 0;
	if (!bit)
		bit = 0;
	if (signal == SIGUSR1)
		ch = ch | (1 << (7 - bit));
	if (signal == SIGUSR2)
		ch = ch & ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", ch);
		bit = 0;
		ch = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				target_pid;

	target_pid = getpid();
	if (target_pid == -1)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	ft_printf("Server PID: %d\n", target_pid);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sig.sa_handler = &ft_sig_handle;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
