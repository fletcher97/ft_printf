/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:21:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/09 19:17:56 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*aux;

	if (!lst)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	aux = ret;
	while (ft_set64((int64_t *)&lst, (int64_t)lst->next) && aux)
	{
		aux->next = ft_lstnew(f(lst->content));
		aux = aux->next;
	}
	if (!aux)
	{
		ft_lstclear(ret, del);
		ret = NULL;
	}
	return (ret);
}
