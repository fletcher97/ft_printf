/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:54 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/08 09:31:11 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;

	if (!ft_set64((int64_t *)&r, (int64_t)malloc(ft_strlen(s) + 1)))
		return (NULL);
	r = ft_memcpy(r, s, ft_strlen(s) + 1);
	return (r);
}
