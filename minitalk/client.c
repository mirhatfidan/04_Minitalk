/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:55:08 by mfidan            #+#    #+#             */
/*   Updated: 2022/04/27 16:55:26 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_sent;

char	*message(char *str)
{
	char	*pid;
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	pid = ft_itoa(getpid());
	ret = (char *)calloc(sizeof(char), ft_strlen(pid) + ft_strlen(str) + 3);
	while (str[++j])
		ret[++i] = str[j];
	j = -1;
	ret[++i] = 2;
	while (pid[++j])
		ret[++i] = pid[j];
	ret[++i] = 3;
	return (ret);
}

void	send_signal(int pid, char *msg)
{
	int				i;
	int				j;
	unsigned int	bin;

	i = 0;
	j = 0;
	while (msg[i] != '\0')
	{
		bin = 1 << 7;
		while (j < 8)
		{
			if (msg[i] & bin)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			bin >>= 1;
			j++;
		}
		i++;
		j = 0;
	}
}

void	handler(int sig)
{
	g_sent = sig;
	ft_printf("\033[2K\r\033[0;32m[Mesaj İletildi]\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("\033[2K\r\033[0;33m([Hatalı argüman girişi])\n");
		exit(1);
	}
	signal(SIGUSR1, handler);
	send_signal(ft_atoi(argv[1]), message(argv[2]));
	if (g_sent == 0)
	{
		ft_printf("\033[2K\r\033[0;31m(Mesaj İletilemedi)\n");
		exit(1);
	}
}
