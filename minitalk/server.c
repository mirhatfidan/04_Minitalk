/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:56:04 by mfidan            #+#    #+#             */
/*   Updated: 2022/04/27 17:00:24 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_pid;

void	read_message(char c)
{
	static int	i;
	static int	j;

	if (c == 2)
	{
		i++;
		write(1, "\n", 1);
	}
	if (c != 2 && i == 0)
		write(1, &c, 1);
	if (i > 0 && c != 2 && c != 3)
		j = (j * 10) + (c - '0');
	if (c == 3)
	{
		g_pid = j;
		i = 0;
		j = 0;
	}
}

static void	handler(int signum)
{
	static int				i;
	static unsigned char	x;

	x <<= 1;
	i++;
	if (signum == SIGUSR2)
		x |= 1;
	if (i == 8)
	{
		read_message(x);
		i = 0;
		x = 0;
	}
	if (g_pid > 0)
	{
		write(1, "> ", 2);
		kill(g_pid, SIGUSR1);
		g_pid = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	write(1, "> ", 2);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
