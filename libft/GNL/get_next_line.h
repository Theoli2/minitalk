/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:32:34 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/07 17:27:32 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft.h"

char	*get_next_line(int fd);
//char	*ft_strchr(const char *s, int c);
//size_t	ft_strlen(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char	*ft_strjoin_gnl(char *s1, const char *s2);

#endif