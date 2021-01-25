/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:54 by mgueifao          #+#    #+#             */
/*   Updated: 2020/12/01 09:47:33 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *r;

	if (!(r = malloc(ft_strlen(s) + 1)))
		return (NULL);
	r = ft_memcpy(r, s, ft_strlen(s) + 1);
	return (r);
}
