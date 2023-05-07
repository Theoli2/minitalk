/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:23:58 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/07 00:59:06 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

int	send_bit(int pid, unsigned char c, int j)
{
	if ((c >> j) & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	return (++j);
}

void	send(int pid, unsigned char *str)
{
	static int				i = 0;
	static int				j = 0;
	static int				st_pid = 0;
	static unsigned char	*st_str = NULL;

	if (pid && str)
	{
		st_pid = pid;
		st_str = str;
	}
	j = send_bit(st_pid, st_str[i], j);
	if (j == 8)
	{
		i++;
		j = 0;
	}
}

void	receive(int sig)
{
	if (sig == SIGUSR1)
		send(0, NULL);
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
	else
		return (write(2, "wrong signal, forbidden", 23), exit(EXIT_FAILURE));
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	*str;

	if (argc != 3)
		return (write(2, "wrong number of arguments !", 27), 1);
	pid = ft_atoi(argv[1]);
	if (pid < 0 || !pid)
		return (write(2, "wrong pid !", 11), 1);
	str = (unsigned char *)argv[argc - 1];
	send(pid, str);
	signal(SIGUSR1, &receive);
	signal(SIGUSR2, &receive);
	while (1)
		pause();
	return (0);
}
