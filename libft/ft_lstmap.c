/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:50:52 by tlivroze          #+#    #+#             */
/*   Updated: 2023/03/06 16:56:06 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*height;

	new = NULL;
	while (lst)
	{
		height = ft_lstnew(f(lst->content));
		if (!height && new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		if (!new)
			new = height;
		else
			ft_lstadd_back(&new, height);
		lst = lst->next;
	}
	return (new);
}
