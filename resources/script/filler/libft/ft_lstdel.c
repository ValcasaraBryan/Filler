/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:55:19 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 12:19:59 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nextt;

	cur = *alst;
	while (cur && del)
	{
		nextt = cur->next;
		*alst = cur;
		ft_lstdelone(alst, (*del));
		cur = cur->next;
	}
}
