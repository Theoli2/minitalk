/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:39:23 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/03 00:43:58 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	subprintf(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += printpercent();
	else if (c == 'c')
		count += printchar(va_arg(args, int));
	else if (c == 's')
		count += printstring(va_arg(args, char *));
	else if (c == 'p')
		count += printadress(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		count += printdecimal(va_arg(args, int));
	else if (c == 'u')
		count += printunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += printhexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += printhexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (count);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			count += subprintf(s[++i], args);
		else
			count += printchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
