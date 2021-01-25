/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:08 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uc	*c1;
	t_uc	*c2;
	size_t	i;

	if (!n)
		return (0);
	c1 = (t_uc*)s1;
	c2 = (t_uc*)s2;
	i = 0;
	while (i < n && c1[i] == c2[i])
		i++;
	i += i == n ? -1 : 0;
	return (c1[i] - c2[i]);
}
