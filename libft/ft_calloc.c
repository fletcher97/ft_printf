/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:18:55 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/07 10:35:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	of_s(size_t s, size_t n)
{
	size_t m;

	if (!s)
		return (0);
	m = (size_t)-1;
	return ((m / s) < n);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	char *p;

	if (of_s(nmemb, size) || !(p = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(p, nmemb * size);
	return ((void *)p);
}
