/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:19:45 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 17:18:57 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	subprintf(const char c, va_list args);
int	printchar(int c);
int	printdecimal(int i);
int	printpercent(void);
int	printstring(char *s);
int	printunsigned(unsigned int u);
int	printhexa(unsigned long x, char *base);
int	printadress(unsigned long a);

#endif