/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:21:42 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:46:55 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *aux;

	if (!lst)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	aux = ret;
	while ((lst = lst->next))
	{
		aux->next = ft_lstnew(f(lst->content));
		aux = aux->next;
	}
	ft_lstclear(&lst, del);
	return (ret);
}
