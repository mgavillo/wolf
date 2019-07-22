/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:36:24 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 17:52:18 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new = f(lst);
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
