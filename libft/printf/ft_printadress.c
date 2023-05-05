/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:49 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 14:27:49 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printadress(unsigned long a)
{
	int	count;

	if (!a)
		return (write(1, "(nil)", 5), 5);
	count = printstring("0x");
	count += printhexa(a, "0123456789abcdef");
	return (count);
}
