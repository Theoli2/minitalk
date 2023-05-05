/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:18:23 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/05 16:49:55 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

int	g_cur = 0;

unsigned char	*ft_realloc(unsigned char *str)
{
	unsigned char	*tmp;

	if (str == NULL)
	{
		str = malloc(sizeof(unsigned char));
		return (str);
	}
	tmp = malloc(sizeof(unsigned char) * (strlen((char *)str) + 1));
	if (tmp == NULL)
		return (NULL);
	free(str);
	return (tmp);
}

void	signalhandler(int sig, siginfo_t *pid, void *ok)
{
	static int		i = 0;
	unsigned char	*str;

	(void)ok;
	g_cur |= (sig == SIGUSR1) << i;
	i++;
	str = NULL;
	if (i == 8)
	{
		if (str == NULL)
			str = malloc(sizeof(unsigned char));
		else
			str = ft_realloc(str);
		str[ft_strlen((char *)str)] = (unsigned char)g_cur;
	}
	g_cur = 0;
	kill(pid->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = &signalhandler;
	siga.sa_flags = SA_SIGINFO;
	ft_printf("%i\n", getpid());
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		continue ;
	return (0);
}
