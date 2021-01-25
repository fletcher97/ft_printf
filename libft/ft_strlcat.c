/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:05 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:39 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	size_t	i;
	size_t	r;

	r = (ft_strlen(dst) > dstsize ? dstsize : ft_strlen(dst)) + ft_strlen(src);
	if (dstsize > ft_strlen(dst))
	{
		d = dst + ft_strlen(dst);
		dstsize -= ft_strlen(dst);
		i = 0;
		while (i < dstsize && src[i])
		{
			d[i] = src[i];
			i++;
		}
		i -= i == dstsize ? 1 : 0;
		d[i] = '\0';
	}
	return (r);
}
