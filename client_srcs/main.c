/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:23:58 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/05 13:42:20 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

int	g_ping = 1;

void	ping(int sig)
{
	if (sig == SIGUSR1)
		g_ping = 1;
}

int	convsignal(int pid, unsigned char *str)
{
	int				i;
	int				j;
	unsigned char	sig;

	(void)pid;
	i = 0;
	while (str[i])
	{
		sig = str[i];
		printf("%c\n", sig);
		j = 0;
		while (j < 8 && g_ping)
		{
			g_ping = 0;
			if (sig % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			sig = sig / 2;
			if (g_ping == 0)
				pause();
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	*str;

	if (argc != 3)
		return (printf("wrong number of arguments !"), 1);
	pid = ft_atoi(argv[1]);
	str = (unsigned char *)argv[argc - 1];
	signal(SIGUSR1, &ping);
	convsignal(pid, str);
	return (0);
}
