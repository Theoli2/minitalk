/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:50 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 15:09:43 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	subprintdecimal(int i)
{
	int		count;

	count = 0;
	if (i == INT_MIN)
		return (printstring("-2147483648"), 11);
	if (i < 0)
	{
		count++;
		write(1, "-", 1);
		i = -i;
	}
	if (i > 0)
	{
		count += subprintdecimal(i / 10);
		count++;
		printchar((i % 10) + 48);
		return (count);
	}
	return (count);
}

int	printdecimal(int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (write(1, "0", 1), 1);
	count += subprintdecimal(i);
	return (count);
}
