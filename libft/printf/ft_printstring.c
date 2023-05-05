/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:48 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 14:23:52 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstring(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6), 6);
	while (s[i++])
		count ++;
	write (1, s, count);
	return (count);
}
