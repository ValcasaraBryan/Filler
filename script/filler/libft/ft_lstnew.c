/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:10:53 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/08 04:58:45 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *mlist;

	if ((mlist = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((mlist->content = (void*)(ft_memalloc(content_size))) == NULL)
			return (NULL);
		ft_memcpy(mlist->content, content, content_size);
		mlist->content_size = content_size;
	}
	else
	{
		mlist->content = NULL;
		mlist->content_size = 0;
	}
	mlist->next = NULL;
	return (mlist);
}
