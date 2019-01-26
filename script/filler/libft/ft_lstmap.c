/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:28:47 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 15:18:10 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mlist;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	mlist = new;
	while (lst->next)
	{
		lst = lst->next;
		mlist->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		mlist = mlist->next;
	}
	return (new);
}
