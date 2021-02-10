/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:04 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:05 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uc	*p;
	size_t	i;

	p = (t_uc*)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == ((t_uc)c))
			return (&(p[i]));
		i++;
	}
	return (NULL);
}
