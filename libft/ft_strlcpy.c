/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:10 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:41 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (!src)
		return (0);
	if (dstsize)
	{
		i = -1;
		while (++i < dstsize && src[i])
			dst[i] = src[i];
		if (i == dstsize)
			i--;
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
