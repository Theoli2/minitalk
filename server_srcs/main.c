/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:18:23 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/07 03:15:20 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

int	g_cur = 0;

unsigned char	*ft_realloc(unsigned char *str, char c)
{
	int				i;
	unsigned char	*tmp;

	i = -1;
	if (str == NULL)
	{
		str = malloc(sizeof(unsigned char));
		if (str == NULL)
			exit(EXIT_FAILURE);
		return (str);
	}
	tmp = malloc(sizeof(unsigned char) * (ft_strlen((char *)str) + 2));
	if (tmp == NULL)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	tmp[ft_strlen((char *)str)] = c;
	tmp[ft_strlen((char *)str) + 1] = '\0';
	while (str[++i])
		tmp[i] = str[i];
	free(str);
	return (tmp);
}

void	displaystring(unsigned char **str, int pid)
{
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
	kill(pid, SIGUSR2);
}

void	signalhandler(int sig, siginfo_t *pid, void *ok)
{
	static int				i = 0;
	static unsigned char	*str = NULL;

	(void)ok;
	g_cur |= (sig == SIGUSR2) << i;
	i++;
	if (i == 8)
	{
		if (str == NULL)
		{
			str = malloc(sizeof(unsigned char) * 2);
			if (str == NULL)
				return (exit(EXIT_FAILURE));
			str[0] = g_cur;
			str[1] = '\0';
		}
		else
			str = ft_realloc(str, g_cur);
		if (g_cur == 0)
			displaystring(&str, pid->si_pid);
		g_cur = 0;
		i = 0;
	}
	kill(pid->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = &signalhandler;
	siga.sa_flags = SA_SIGINFO;
	sigemptyset(&siga.sa_mask);
	ft_printf("%i\n", getpid());
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		continue ;
	return (0);
}
