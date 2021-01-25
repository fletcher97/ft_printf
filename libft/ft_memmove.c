/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:16 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/12 19:01:40 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		inc;
	size_t	i;
	t_uc	*d;
	t_uc	*s;

	if (!dest && !src)
		return (0);
	if (!n)
		return (dest);
	d = (t_uc*)dest;
	s = (t_uc*)src;
	inc = dest < src ? 1 : -1;
	i = dest < src ? 0 : n - 1;
	n = dest < src ? n : 0;
	while (i != n)
	{
		d[i] = s[i];
		i += inc;
	}
	if (!i)
		d[i] = s[i];
	return (dest);
}
